/*
 * File:   main.cpp
 * Author: m1cha
 *
 * Created on April 25, 2012, 8:08 PM
 */

#include <cstdlib>
#include <stdio.h>

extern "C" {
	#include <pixelflinger/pixelflinger.h>
	#include "minui/minui.h"
}

//FreeType Headers
#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>

void font_test(const char * fname, unsigned int h) {
	// Create and initilize a freetype font library.
	FT_Library library;
	if (FT_Init_FreeType( &library )) {
		printf("FT_Init_FreeType failed\n");fflush(stdout);return;
	}

	FT_Face face;
	if (FT_New_Face( library, fname, 0, &face )) {
		printf("FT_New_Face failed (there is probably a problem with your font file)\n");fflush(stdout);return;
	}

	char ch = 'Z';
	FT_Set_Char_Size( face, h << 6, h << 6, 96, 96);

	// Load the Glyph for our character.
	if(FT_Load_Glyph( face, FT_Get_Char_Index( face, ch ), FT_LOAD_DEFAULT )) {
		printf("FT_Load_Glyph failed\n");fflush(stdout);return;
	}

	// Move the face's glyph into a Glyph object.
	FT_Glyph glyph;
	if(FT_Get_Glyph( face->glyph, &glyph )) {
		printf("FT_Get_Glyph failed\n");fflush(stdout);return;
	}

	//Convert the glyph to a bitmap.
	FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
	FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
	FT_Bitmap& bitmap=bitmap_glyph->bitmap;
	int width = bitmap.width;
	int height = bitmap.rows;

	// TODO convert bitmap to GGLSurface
	GGLSurface* surface = gr_get_surface();
	memcpy(surface->data, bitmap.buffer,
			   width*height);

	FT_Done_Face(face);
	FT_Done_FreeType(library);
}

/*
 *
 */
int main(int argc, char** argv) {
	gr_init();

	font_test("/system/fonts/DroidSans.ttf", 32);
	gr_flip();

	return EXIT_SUCCESS;
}
