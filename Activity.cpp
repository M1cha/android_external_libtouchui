/*
 * Activity.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: m1cha
 */

#include "Activity.h"


TouchUi::Activity::Activity() {
	printf("Activity()\n");fflush(stdout);
}

TouchUi::Activity::~Activity() {
	printf("~Activity()\n");fflush(stdout);
}

void TouchUi::Activity::onLoad() {

}

void TouchUi::Activity::onUnload() {

}

void TouchUi::Activity::addView(View *v) {
	std::list<View*>::iterator pos;
	pos = find(this->_views.begin(), this->_views.end(), v);

	// element is not in list
	if(pos==this->_views.end()) {
		this->_views.push_back(v);
		v->setParent(this);
		v->onLoad();
	}
}

void TouchUi::Activity::onDraw(Canvas *c) {


	struct Color red = Color(255,0,0,255);
	c->setColor(&red);
	c->drawRect(0,0,c->getWidth(),c->getHeight());
}
