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
