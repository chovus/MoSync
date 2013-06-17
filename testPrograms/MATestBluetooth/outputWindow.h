/*
 * outputWindow.h
 *
 *  Created on: Jun 17, 2013
 *      Author: ovidel
 */

#ifndef OUTPUTWINDOW_H_
#define OUTPUTWINDOW_H_

#include <MAUtil/Moblet.h>
#include <NativeUI/ButtonListener.h>

namespace NativeUI
{
	class Widget;
	class Screen;
	class Button;
	class Label;
	class VerticalLayout;
}


class OutputWindow : public MAUtil::Moblet, public NativeUI::ButtonListener
{
public:
	OutputWindow();
	virtual ~OutputWindow();

	void createUI();
	void keyPressEvent(int keyCode, int nativeCode);
	virtual void buttonClicked(NativeUI::Widget* button);

private:
	NativeUI::Screen* mScreen;
	NativeUI::VerticalLayout* mLayout;
	NativeUI::Button* mButton;
	NativeUI::Label* mMessage;
};

#endif /* OUTPUTWINDOW_H_ */
