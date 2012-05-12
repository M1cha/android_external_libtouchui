/*
 * TouchEvent.cpp
 *
 *  Created on: Apr 29, 2012
 *      Author: m1cha
 */

#include "TouchEvent.h"

namespace TouchUi {

TouchEvent::TouchEvent(input_event *e, int action) {
	this->event = e;
	this->action = action;
}

TouchEvent::~TouchEvent() {
}

int TouchEvent::getAction() {
	return this->action;
}

int TouchEvent::getX() {
	int x = this->event->value >> 16;
	return x;
}

int TouchEvent::getY() {
	int y = this->event->value & 0xFFFF;
	return y;
}

} /* namespace TouchUi */
