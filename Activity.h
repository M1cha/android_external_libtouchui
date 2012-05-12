/*
 * Activity.h
 *
 *  Created on: Apr 27, 2012
 *      Author: m1cha
 */

#ifndef ACTIVITY_H_
#define ACTIVITY_H_

#include "Context.h"
#include "views/View.h"
#include "Color.h"
#include "Canvas.h"
#include <list>
#include <stdio.h>
#include "pthread.h"

namespace TouchUi {

class Activity : public Context {
public:
	Activity();
	virtual ~Activity();
	virtual void onLoad();
	virtual void onUnload();
	virtual void setContentView(View *v);
	virtual View* getContentView();
	virtual void onDraw(Canvas *c);
private:
	View* _contentview;
	pthread_mutex_t lock_mutex;
};

} /* namespace TouchUi */
#endif /* ACTIVITY_H_ */
