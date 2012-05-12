/*
 * Image.cpp
 *
 *  Created on: May 12, 2012
 *      Author: m1cha
 */

#include "Image.h"
#include "stdio.h"

namespace TouchUi {

Image::Image(const char* path) {
	gr_surface* s = &this->gr_mem_surface;
	int result = res_create_surface(path, s);
	if (result < 0) {
		if (result == -2) {
			printf("Bitmap missing header\n");
		} else {
			printf("Missing bitmap\n(Code %d)\n", result);
		}
	}
}

Image::~Image() {
	free(this->gr_mem_surface);
}

GGLSurface* Image::getSurface() {
	return (GGLSurface*)this->gr_mem_surface;
}

int Image::getWidth() {
	return gr_get_width(this->gr_mem_surface);
}
int Image::getHeight() {
	return gr_get_height(this->gr_mem_surface);
}

} /* namespace TouchUi */
