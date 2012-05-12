/*
 * AbsoluteLayout.h
 *
 *  Created on: May 7, 2012
 *      Author: m1cha
 */

#ifndef ABSOLUTELAYOUT_H_
#define ABSOLUTELAYOUT_H_

#include "ViewGroup.h"

namespace TouchUi {

class AbsoluteLayout : public ViewGroup {
public:
	AbsoluteLayout();
	virtual ~AbsoluteLayout();
	virtual void onDraw(Canvas *c);
};

} /* namespace TouchUi */
#endif /* ABSOLUTELAYOUT_H_ */
