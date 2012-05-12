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
	virtual void onLoad();
	virtual void onUnload();
	virtual void onDraw(Canvas *c);

	virtual int getPreferredWidth();
	virtual int getPreferredHeight();

	// please note that the position will ignored in all layouts except AbsoluteLayout
	virtual void setPosX(int x);
	virtual void setPosY(int y);
	virtual int getPosX();
	virtual int getPosY();
private:
	int _x;
	int _y;
};

} /* namespace TouchUi */
#endif /* VIEW_H_ */
