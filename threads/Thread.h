/*
 * Thread.h
 *
 *  Created on: Apr 28, 2012
 *      Author: m1cha
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h>

namespace TouchUi {

extern "C" void *ThreadStartup(void *_tgtObject);

class Thread {
public:
	Thread();
	virtual ~Thread();
	virtual void run();
	int start();
	void stop();
	void join();
	bool requestedExit();
private:
	pthread_t _thread;
};

} /* namespace TouchUi */
#endif /* THREAD_H_ */
