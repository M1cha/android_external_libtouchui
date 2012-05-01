/*
 * Gui.cpp
 *
 *  Created on: Apr 25, 2012
 *      Author: m1cha
 */

#include "UiMain.h"

TouchUi::UiMain::UiMain() {
	this->_is_uimain = true;
	exit_mutex = PTHREAD_MUTEX_INITIALIZER;
	exit_cond = PTHREAD_COND_INITIALIZER;

	gr_init();
	ev_init();
}

TouchUi::UiMain::~UiMain() {
	ev_exit();
	gr_exit();
}

void TouchUi::UiMain::addActivity(Activity *a) {
	std::list<Activity*>::iterator pos;
	pos = find(this->_activities.begin(), this->_activities.end(), a);

	// element is not in list
	if(pos==this->_activities.end()) {
		this->_activities.push_back(a);
		a->setParent(this);
		a->onLoad();
	}
}

void TouchUi::UiMain::removeActivity(Activity *a) {
	a->onUnload();
	this->_activities.remove(a);
	a->setParent(NULL);
}

std::list<TouchUi::Activity*>* TouchUi::UiMain::getActivities() {
	return &this->_activities;
}

int TouchUi::UiMain::start() {
	int rc;
	RedrawThread thread_redraw(this);
	EventThread thread_event(this);

	// start RedrawThread
	rc = thread_redraw.start();
	if(rc) {
		printf("RedrawThread exited with code: %d;\n", rc);
		this->~UiMain();
		return -1;
	}

	// start EventThread
	rc = thread_event.start();
	if(rc) {
		printf("EventThread exited with code: %d;\n", rc);
		this->~UiMain();
		return -1;
	}

	// wait for exit-signal
	pthread_mutex_lock(&this->exit_mutex);
	pthread_cond_wait(&this->exit_cond, &this->exit_mutex);
	pthread_mutex_unlock(&this->exit_mutex);

	// stop threads
	thread_redraw.stop();
	thread_event.stop();


	return this->exitCode;
}

void TouchUi::UiMain::onKeyEvent(View *v, KeyEvent *e) {
	printf("onKeyEvent();\n");fflush(stdout);
	this->exit(5);
}

void TouchUi::UiMain::onTouchEvent(View *v, TouchEvent *e) {
	switch(e->getAction()) {
		case TouchEvent::ACTION_START:
		case TouchEvent::ACTION_RELEASE:
			printf("onTouchEvent: (%d,%d);\n", e->getX(), e->getY());fflush(stdout);
		break;
	}
}

void TouchUi::UiMain::exit(int code) {
	this->exitCode = code;
	pthread_cond_signal(&this->exit_cond);
}
