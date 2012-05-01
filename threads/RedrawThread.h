/*
 * RedrawThread.h
 *
 *  Created on: Apr 28, 2012
 *      Author: m1cha
 */

#ifndef REDRAWTHREAD_H_
#define REDRAWTHREAD_H_

extern "C" {
	#include "minui/common.h"
	#include "minui/minui.h"
}
#include <list>
#include "stdlib.h"
#include "string"
#include "Thread.h"
#include "Canvas.h"
#include "Context.h"


namespace TouchUi {

class RedrawThread : public Thread {
public:
	RedrawThread(Context *c);
	virtual ~RedrawThread();
	void run();
private:
	Context *context;
};

} /* namespace TouchUi */
#endif /* REDRAWTHREAD_H_ */
