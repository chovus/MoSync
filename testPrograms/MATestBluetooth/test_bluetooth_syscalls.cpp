#include <ma.h>

#include "test_bluetooth_syscalls.h"


TestBluetoothSyscalls::TestBluetoothSyscalls(const MAUtil::String& name):
		MATest::TestCase(name)
{
}


TestBluetoothSyscalls::start()
{
#if 0
	test_maBTStart_nodevice();
#endif
	test_maBTStart_devicepresent();
	test_maBTGetPairedDevices_success();
}

/************************************************************************************************
 *
 * the BT test cases
 *
 *************************************************************************************************/

void TestBluetoothSyscalls::test_maBTStart_devicepresent()
{
	int res = maBTStart();

	assert("DevicePresent", res > 0);
	expect("DevicePresentAndEnabled");
}

void TestBluetoothSyscalls::test_maBTStart_nodevice()
{
	int res = maBTStart();

	assert("NoDevice", res == 0);
}

void TestBluetoothSyscalls::test_maBTGetPairedDevices_success()
{
	int res = maBTGetPairedDevices();

	assert("PairedDevices", res > 0);
	assert("NoPairedDevices", res == 0);
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

