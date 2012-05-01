/*
 * TouchEvent.h
 *
 *  Created on: Apr 29, 2012
 *      Author: m1cha
 */

#ifndef TOUCHEVENT_H_
#define TOUCHEVENT_H_

#include <linux/input.h>
#include <stdio.h>

namespace TouchUi {

class TouchEvent {
public:
	TouchEvent(input_event *e, int action);
	virtual ~TouchEvent();
	int getAction();
	int getX();
	int getY();
	static const int ACTION_START = 0;
	static const int ACTION_DRAG = 1;
	static const int ACTION_RELEASE = 2;
private:
	input_event *event;
	int action;
};

} /* namespace TouchUi */
#endif /* TOUCHEVENT_H_ */
