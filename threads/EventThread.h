/*
 * EventThread.h
 *
 *  Created on: Apr 28, 2012
 *      Author: m1cha
 */

#ifndef EVENTTHREAD_H_
#define EVENTTHREAD_H_

#include "Thread.h"
#include "../Context.h"
#include "../events/KeyEvent.h"
#include "../events/TouchEvent.h"
extern "C" {
	#include "minui/common.h"
	#include "minui/minui.h"
	#include <linux/input.h>
	#include <pthread.h>
}

namespace TouchUi {

class EventThread : public Thread {
public:
	EventThread(Context *c);
	virtual ~EventThread();
	void run();
private:
	Context *context;
};

} /* namespace TouchUi */
#endif /* EVENTTHREAD_H_ */
