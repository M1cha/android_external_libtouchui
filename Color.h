/*
 * Color.h
 *
 *  Created on: Apr 30, 2012
 *      Author: m1cha
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <pixelflinger/pixelflinger.h>

namespace TouchUi {

struct Color
{
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		this->color[0] = ((r << 8) | r) + 1;
		this->color[1] = ((g << 8) | g) + 1;
		this->color[2] = ((b << 8) | b) + 1;
		this->color[3] = ((a << 8) | a) + 1;
#ifdef COLORS_REVERSED
		this->color[0] = ((b << 8) | b) + 1;
		this->color[2] = ((r << 8) | r) + 1;
#endif
	}
	GGLint color[4];
};
} /* namespace TouchUi */
#endif /* COLOR_H_ */
