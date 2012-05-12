/*
 * ViewGroup.h
 *
 *  Created on: May 7, 2012
 *      Author: m1cha
 */

#ifndef VIEWGROUP_H_
#define VIEWGROUP_H_

#include "View.h"
#include <list>

namespace TouchUi {

class ViewGroup : public View {
public:
	ViewGroup();
	virtual ~ViewGroup();
	virtual void addView(View *v);
	virtual void removeView(View *v);
	virtual std::list<View*>* getViews();
private:
	std::list<View*> _views;
};

} /* namespace TouchUi */
#endif /* VIEWGROUP_H_ */
