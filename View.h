/*
 * GuiControl.h
 *
 *  Created on: Apr 26, 2012
 *      Author: m1cha
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "Context.h"

namespace TouchUi {

class View : public Context {
public:
	View();
	virtual ~View();
	void onLoad();
	void onUnload();
	virtual void onDraw(Canvas *c);
};

} /* namespace TouchUi */
#endif /* VIEW_H_ */
