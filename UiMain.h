/*
 * UiMain.h
 *
 *  Created on: Apr 25, 2012
 *      Author: m1cha
 */

#ifndef UIMAIN_H_
#define UiMain_H_

#include "Context.h"
#include "Activity.h"
#include <list>
#include "threads/RedrawThread.h"
#include "threads/EventThread.h"

namespace TouchUi {

class UiMain : public Context {
public:
	UiMain();
	virtual ~UiMain();
	void addActivity(Activity *a);
	void removeActivity(Activity *a);
	std::list<Activity*>* getActivities();
	int start();
	void onKeyEvent(View *v, struct KeyEvent *e);
	void onTouchEvent(View *v, struct TouchEvent *e);
	void exit(int code);
protected:
private:
	std::list<Activity*> _activities;
	int exitCode;
	pthread_mutex_t exit_mutex;
	pthread_cond_t exit_cond;
};

} /* namespace TouchUi */
#endif /* UIMAIN_H_ */
