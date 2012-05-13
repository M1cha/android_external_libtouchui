/*
 * GuiControl.cpp
 *
 *  Created on: Apr 26, 2012
 *      Author: m1cha
 */


#include "View.h"
#include "Canvas.h"

TouchUi::View::View() {
	this->_x = 0;
	this->_y = 0;
}

TouchUi::View::~View() {
}

void TouchUi::View::onLoad() {

}

void TouchUi::View::onUnload() {

}

void TouchUi::View::onDraw(Canvas *c) {
	Color red(255,0,0,255);
	c->setColor(&red);
	c->drawRect(0,0,c->getWidth(),c->getHeight());

	Image img("/system/bootmenu/images/background.png");
	//c->drawImage(&img, 0, 0);

	Image img2("/tmp/fonts/helvetica-big.png");
	c->drawImage(&img2, 0, 0);
}

void TouchUi::View::setPosX(int x) {
	this->_x = x;
}
void TouchUi::View::setPosY(int y) {
	this->_y = y;
}
int TouchUi::View::getPosX() {
	return this->_x;
}
int TouchUi::View::getPosY() {
	return this->_y;
}

int TouchUi::View::getPreferredWidth() {
	return gr_fb_width();
}
int TouchUi::View::getPreferredHeight() {
	return gr_fb_height();
}
