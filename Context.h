/*
 * Context.h
 *
 *  Created on: Apr 27, 2012
 *      Author: m1cha
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <stdio.h>
#include "TouchUiCommon.h"

namespace TouchUi {

class Context {
public:
	Context();
	virtual ~Context();
	UiMain* getUiMain();
	void setParent(Context *c);
	Context* getParent();
	bool isUiMain();
	bool _is_uimain;
private:
	Context *_parent;
	char *_name;
protected:

};

} /* namespace TouchUi */
#endif /* CONTEXT_H_ */
