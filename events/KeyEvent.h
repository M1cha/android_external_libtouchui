/*
 * KeyEvent.h
 *
 *  Created on: Apr 29, 2012
 *      Author: m1cha
 */

#ifndef KEYEVENT_H_
#define KEYEVENT_H_

#include <linux/input.h>
#include <stdio.h>

namespace TouchUi {

class KeyEvent {
public:
	KeyEvent(input_event *e);
	virtual ~KeyEvent();
	int getAction();
	int getKeyCode();
	static const int ACTION_DOWN = 1;
	static const int ACTION_UP = 0;
private:
	input_event *event;
};

} /* namespace TouchUi */
#endif /* KEYEVENT_H_ */
