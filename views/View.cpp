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
	return 0;
}
int TouchUi::View::getPreferredHeight() {
	return 0;
}
