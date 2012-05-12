/*
 * ViewGroup.cpp
 *
 *  Created on: May 7, 2012
 *      Author: m1cha
 */

#include "ViewGroup.h"

namespace TouchUi {

ViewGroup::ViewGroup() {
	// TODO Auto-generated constructor stub

}

ViewGroup::~ViewGroup() {
	// TODO Auto-generated destructor stub
}

void ViewGroup::addView(View *v) {
	std::list<View*>::iterator pos;
	pos = find(this->_views.begin(), this->_views.end(), v);

	// element is not in list
	if(pos==this->_views.end()) {
		this->_views.push_back(v);
		v->setParent(this);
		v->onLoad();
	}
}

void ViewGroup::removeView(View *v) {
	v->onUnload();
	this->_views.remove(v);
	v->setParent(NULL);
}

std::list<View*>* ViewGroup::getViews() {
	return &this->_views;
}


} /* namespace TouchUi */
