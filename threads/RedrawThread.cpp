/*
 * RedrawThread.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: m1cha
 */

#include "RedrawThread.h"
#include "UiMain.h"

TouchUi::RedrawThread::RedrawThread(Context *c) {
	// save context
	this->context = c;
}

TouchUi::RedrawThread::~RedrawThread() {
	// TODO Auto-generated destructor stub
}

void TouchUi::RedrawThread::run() {
	printf("RedrawThread::run();\n");fflush(stdout);

	bool bExitFlag = false;
	while (!bExitFlag) {
		usleep(1000000 / 15);

		// clear screen
		gr_color(0, 0, 0, 255);
		gr_fill(0, 0, gr_fb_width(), gr_fb_height());


		// draw activities
		std::list<Activity*>* activities = this->context->getUiMain()->getActivities();
		for(std::list<Activity*>::iterator it = activities->begin(); it != activities->end(); it++) {
			Canvas c(gr_fb_width(), gr_fb_height());
			(*it)->onDraw(&c);
			gr_blit(c.getSurface(), 0,0, c.getWidth(),c.getHeight(), 0,0);
		}

		// write buffer
		gr_flip();

		bExitFlag = this->requestedExit();
	}
	printf("RedrawThread::exit()\n");fflush(stdout);
}
