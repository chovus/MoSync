#include <ma.h>

#include "test_bluetooth_syscalls.h"


TestBluetoothSyscalls::TestBluetoothSyscalls(const MAUtil::String& name):
		MATest::TestCase(name)
{
}


TestBluetoothSyscalls::start()
{
	test_maBtStart_devicepresent();
}

/************************************************************************************************
 *
 * the BT test cases
 *
 *************************************************************************************************/

void TestBluetoothSyscalls::test_maBtStart_devicepresent()
{
	int res = maBTStart();

	assert("DevicePresent", res > 0);
	expect("DevicePresentAndEnabled");
}

void TestBluetoothSyscalls::test_maBtStart_nodevice()
{
	int res = maBTStart();

	asser("NoDevice", res == 0);
}

/************************************************************************************************
 *
 * Call-backs for the BT's asynchronous events
 *
 *************************************************************************************************/

void TestBluetoothSyscalls::onBTStarted(int err_code)
{
	assert("DevicePresentAndEnabled", err_code == MA_BT_OK); // device enabled
	runNextTestCase();
}



TESTCASE(TestBluetoothSyscalls)

