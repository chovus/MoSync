/*
 * outputWindow.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: ovidel
 */

#include <NativeUI/WidgetUtil.h>
#include <NativeUI/Widget.h>
#include <NativeUI/Screen.h>
#include <NativeUI/Button.h>
#include <NativeUI/Label.h>
#include <NativeUI/VerticalLayout.h>

#include "TestRunner.h"

#include "outputWindow.h"

OutputWindow::OutputWindow()
{
	createUI();
}


OutputWindow::~OutputWindow()
{
	mButton->removeButtonListener(this);
	// All the children will be deleted.
	delete mScreen;
}


void OutputWindow::createUI()
{
	// Create a NativeUI screen that will hold layout and widgets.
	mScreen = new NativeUI::Screen();

	//Create a Vertical Layout that will hold widgets
	mLayout = new NativeUI::VerticalLayout();

	//Let the layout fill the entire screen
	mLayout->fillSpaceHorizontally();
	mLayout->fillSpaceVertically();

	mButton = new NativeUI::Button();
	mButton->fillSpaceHorizontally();
	mButton->addButtonListener(this);
	mButton->setText("Run BlueTooth Test Suite");
	mLayout->addChild(mButton);

	mMessage = new NativeUI::Label();
	mMessage->fillSpaceHorizontally();
	mMessage->setMaxNumberOfLines(0);
	mMessage->setText("No tests run yet");
	mLayout->addChild(mMessage);

	mScreen->setMainWidget(mLayout);
	mScreen->show();
}


void OutputWindow::keyPressEvent(int keyCode, int nativeCode)
{
	if (MAK_BACK == keyCode || MAK_0 == keyCode)
	{
		close();
	}
}


void OutputWindow::buttonClicked(NativeUI::Widget* button)
{
	mButton->setEnabled(false);
	mMessage->setText("tests are running...");

	TestRunner::getInstance()->addTestListener(new SimpleTestListener());
	TestRunner::getInstance()->runNextTestCase();
}


