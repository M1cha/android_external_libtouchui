/*
 * EventThread.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: m1cha
 */

#include "EventThread.h"
#include "UiMain.h"

TouchUi::EventThread::EventThread(Context *c) {
	// save context
	this->context = c;
}

TouchUi::EventThread::~EventThread() {
	// TODO Auto-generated destructor stub
}

void TouchUi::EventThread::run() {
	printf("EventThread::run();\n");fflush(stdout);
	int drag = 0;
	bool bExitFlag = false;


	while (!bExitFlag) {
		// wait for the next key event
		struct input_event ev;
		int state = 0;
		int action = -1;

		// get input-event
		do {ev_get(&ev, 0);}
		while ((ev.type != EV_KEY && ev.type != EV_ABS) || ev.code > KEY_MAX || ev.value<0);

		// KeyEvent's
		if (ev.type == EV_KEY) {
			KeyEvent ke(&ev);
			this->context->getUiMain()->onKeyEvent(NULL, &ke);
		}

		// Touch-Events
		else if (ev.type == EV_ABS) {

			if (ev.code == 0) {
				if (state == 0) {
					action = TouchEvent::ACTION_RELEASE;
				}
				state = 0;
				drag = 0;
			}
			else {
				if (!drag) {
					action = TouchEvent::ACTION_START;
					drag=1;
				}
				else if (state == 0) {
					action = TouchEvent::ACTION_DRAG;
				}
			}

			if(action!=-1) {
				TouchEvent te(&ev, action);
				this->context->getUiMain()->onTouchEvent(NULL, &te);
			}
		}

		bExitFlag = this->requestedExit();
	} // thread loop
	printf("EventThread::exit()\n");fflush(stdout);
}
