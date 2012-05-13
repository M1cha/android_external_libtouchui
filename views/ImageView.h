/*
 * ImageView.h
 *
 *  Created on: May 13, 2012
 *      Author: m1cha
 */

#ifndef IMAGEVIEW_H_
#define IMAGEVIEW_H_

#include "../Image.h"
#include "../Canvas.h"
#include "View.h"

namespace TouchUi {

class ImageView : public View {
public:
	ImageView(Image *img);
	virtual ~ImageView();
	virtual void onDraw(Canvas *c);
	virtual int getPreferredWidth();
	virtual int getPreferredHeight();
private:
	Image *_img;
};

} /* namespace TouchUi */
#endif /* IMAGEVIEW_H_ */
