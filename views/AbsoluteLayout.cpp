/*
 * AbsoluteLayout.cpp
 *
 *  Created on: May 7, 2012
 *      Author: m1cha
 */

#include "AbsoluteLayout.h"
#include "Canvas.h"

namespace TouchUi {

AbsoluteLayout::AbsoluteLayout() {
	// TODO Auto-generated constructor stub

}

AbsoluteLayout::~AbsoluteLayout() {
	// TODO Auto-generated destructor stub
}

void AbsoluteLayout::onDraw(Canvas *c) {
	// draw all views in this ViewGroup
	std::list<View*>* views = this->getViews();
	for(std::list<View*>::iterator it = views->begin(); it != views->end(); it++) {
		// create canvas for view
		Canvas canvas_view((*it)->getPreferredWidth(), (*it)->getPreferredHeight());

		// render the view
		(*it)->onDraw(&canvas_view);

		// draw view's canvas on this layout's canvas
		c->drawCanvas(&canvas_view, (*it)->getPosX(), (*it)->getPosY());
	}
}

} /* namespace TouchUi */
