/*
 * Activity.h
 *
 *  Created on: Apr 27, 2012
 *      Author: m1cha
 */

#ifndef ACTIVITY_H_
#define ACTIVITY_H_

#include "Context.h"
#include "View.h"
#include "Color.h"
#include "Canvas.h"
#include <list>
#include <stdio.h>

namespace TouchUi {

class Activity : public Context {
public:
	Activity();
	virtual ~Activity();
	void onLoad();
	void onUnload();
	void addView(View *v);
	virtual void onDraw(Canvas *c);
private:
	std::list<View*> _views;
};

} /* namespace TouchUi */
#endif /* ACTIVITY_H_ */
