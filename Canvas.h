/*
 * Canvas.h
 *
 *  Created on: Apr 29, 2012
 *      Author: m1cha
 */

#ifndef CANVAS_H_
#define CANVAS_H_

extern "C" {
	#include <pixelflinger/pixelflinger.h>
	#include "minui/minui.h"
}
#include "Color.h"

namespace TouchUi {

class Canvas {
public:
	Canvas(int width, int height);
	virtual ~Canvas();
	void setColor(struct Color* c);
	GGLSurface* getSurface();
	void drawRect(int left, int top, int right, int bottom);
	int getWidth();
	int getHeight();
private:
	GGLContext *gl;
	GGLSurface gr_mem_surface;
	void get_memory_surface(GGLSurface* ms, __u32 w, __u32 h);
};

} /* namespace TouchUi */
#endif /* CANVAS_H_ */
