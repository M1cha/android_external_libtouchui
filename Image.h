/*
 * Image.h
 *
 *  Created on: May 12, 2012
 *      Author: m1cha
 */

#ifndef IMAGE_H_
#define IMAGE_H_

extern "C" {
	#include <pixelflinger/pixelflinger.h>
	#include "minui/minui.h"
}

namespace TouchUi {

class Image {
public:
	Image(const char* path);
	virtual ~Image();
	GGLSurface* getSurface();
	int getWidth();
	int getHeight();
private:
	gr_surface gr_mem_surface;
};

} /* namespace TouchUi */
#endif /* IMAGE_H_ */
