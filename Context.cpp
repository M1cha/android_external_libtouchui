/*
 * Context.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: m1cha
 */

#include "Context.h"
#include "UiMain.h"

TouchUi::Context::Context() {
	// TODO Auto-generated constructor stub
	printf("Context()\n");fflush(stdout);
	this->_is_uimain = false;
	this->_parent = NULL;
}

TouchUi::Context::~Context() {
	// TODO Auto-generated destructor stub
	printf("~Context()\n");fflush(stdout);
}

TouchUi::UiMain* TouchUi::Context::getUiMain() {
	Context* context;
	for(context=this; context!=NULL; context=context->getParent()) {
		if(context->isUiMain()) {
			return (UiMain*)context;
		}
	}
	return NULL;
}

void TouchUi::Context::setParent(Context *c) {
	this->_parent = c;

}

TouchUi::Context* TouchUi::Context::getParent() {
	return this->_parent;
}

bool TouchUi::Context::isUiMain() {
	return this->_is_uimain;
}
