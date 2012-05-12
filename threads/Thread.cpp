/*
 * Thread.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: m1cha
 */

#include "Thread.h"

namespace TouchUi {

	extern "C" void *ThreadStartup(void *_tgtObject) {
		Thread *tgtObject = (Thread *)_tgtObject;
		tgtObject->run();
		return NULL;
	}

	Thread::Thread() {
		this->_thread = 0;
	}

	Thread::~Thread() {
		this->stop();
	}

	void Thread::run() {}

	int Thread::start() {
		int ret = -1;

		if(this->_thread==0) {
			// create and start thread
			ret = pthread_create(&_thread, NULL, ThreadStartup, this);
		}

		return ret;
	}

	void Thread::stop() {
		if (this->_thread != 0) {
			pthread_detach(this->_thread);
			this->_thread = 0;
			usleep(1000);
		}
	}

	void Thread::join() {
		pthread_join(_thread, NULL);
	}

	bool Thread::requestedExit() {
		return (this->_thread == 0);
	}

} /* namespace TouchUi */
