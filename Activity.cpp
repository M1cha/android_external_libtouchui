/*
 * Activity.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: m1cha
 */

#include "Activity.h"


TouchUi::Activity::Activity() {
	this->_contentview = NULL;
	this->lock_mutex = PTHREAD_MUTEX_INITIALIZER;
}

TouchUi::Activity::~Activity() {
}

void TouchUi::Activity::onLoad() {

}

void TouchUi::Activity::onUnload() {

}

void TouchUi::Activity::setContentView(View *v) {
	pthread_mutex_lock(&this->lock_mutex);
	this->_contentview = v;
	pthread_mutex_unlock(&this->lock_mutex);
}

TouchUi::View* TouchUi::Activity::getContentView() {
	return this->_contentview;
}

void TouchUi::Activity::onDraw(Canvas *c) {
	pthread_mutex_lock(&this->lock_mutex);
	if(this->_contentview!=NULL) {
		this->_contentview->onDraw(c);
	}
	pthread_mutex_unlock(&this->lock_mutex);
}
