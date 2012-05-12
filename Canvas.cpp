/*
 * Canvas.cpp
 *
 *  Created on: Apr 29, 2012
 *      Author: m1cha
 */

#include "Canvas.h"

TouchUi::Canvas::Canvas(int width, int height) {

	// get GGLContext
	this->gl = 0;
	gglInit(&gl);

	// initialize memory-surface
	this->gr_mem_surface.data = NULL;
	this->get_memory_surface(&this->gr_mem_surface, width, height);
	gl->colorBuffer(gl, &this->gr_mem_surface);
}

TouchUi::Canvas::~Canvas() {
}

void TouchUi::Canvas::drawRect(int left, int top, int right, int bottom) {
	gl->disable(this->gl, GGL_TEXTURE_2D);
	gl->recti(this->gl, left,top, right,bottom);
}

void TouchUi::Canvas::drawCanvas(Canvas *c, int x, int y) {
	gl->bindTexture(this->gl, c->getSurface());
	gl->texEnvi(gl, GGL_TEXTURE_ENV, GGL_TEXTURE_ENV_MODE, GGL_REPLACE);
	gl->texGeni(gl, GGL_S, GGL_TEXTURE_GEN_MODE, GGL_ONE_TO_ONE);
	gl->texGeni(gl, GGL_T, GGL_TEXTURE_GEN_MODE, GGL_ONE_TO_ONE);
	gl->enable(gl, GGL_TEXTURE_2D);
	gl->texCoord2i(gl, 0 - x, 0 - y);
	gl->recti(gl, x, y, x + c->getWidth(), y + c->getHeight());
}

void TouchUi::Canvas::setColor(struct Color* c) {
	this->gl->color4xv(this->gl, c->color);
}

int TouchUi::Canvas::getWidth() {
	return this->gr_mem_surface.width;
}
int TouchUi::Canvas::getHeight() {
	return this->gr_mem_surface.height;
}

void TouchUi::Canvas::get_memory_surface(GGLSurface* ms, __u32 w, __u32 h) {
    ms->version = sizeof(GGLSurface);
    ms->width = w;
    ms->height = h;
    ms->stride = gr_get_fb_fix_screeninfo()->line_length/PIXEL_SIZE;
    ms->data = (GGLubyte*)malloc(h * gr_get_fb_fix_screeninfo()->line_length);
    ms->format = PIXEL_FORMAT;
}

GGLSurface* TouchUi::Canvas::getSurface() {
	return &this->gr_mem_surface;
}
