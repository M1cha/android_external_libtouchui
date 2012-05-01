/*
 * KeyEvent.cpp
 *
 *  Created on: Apr 29, 2012
 *      Author: m1cha
 */

#include "KeyEvent.h"

namespace TouchUi {

KeyEvent::KeyEvent(input_event *e) {
	this->event = e;
}

KeyEvent::~KeyEvent() {
}

int KeyEvent::getKeyCode() {
	return this->event->code;
}

int KeyEvent::getAction() {
	return this->event->value;
}

} /* namespace TouchUi */
