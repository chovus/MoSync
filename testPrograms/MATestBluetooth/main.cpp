
#include "outputWindow.h"


/**
 * Main function that is called when the program starts.
 */
extern "C" int MAMain()
{
	MAUtil::Moblet::run(new OutputWindow());
	return 0;
}
