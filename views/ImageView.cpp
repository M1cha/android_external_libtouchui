/*
 * ImageView.cpp
 *
 *  Created on: May 13, 2012
 *      Author: m1cha
 */

#include "ImageView.h"

namespace TouchUi {

ImageView::ImageView(Image *img) {
	this->_img = img;
}

ImageView::~ImageView() {
	this->_img = NULL;
}

void ImageView::onDraw(Canvas *c) {
	c->drawImage(this->_img, 0, 0);
}

int ImageView::getPreferredWidth() {
	return this->_img->getWidth();
}

int ImageView::getPreferredHeight() {
	return this->_img->getHeight();
}

} /* namespace TouchUi */
