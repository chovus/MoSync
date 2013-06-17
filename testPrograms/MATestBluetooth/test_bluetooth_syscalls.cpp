#include <ma.h>

#include "test_bluetooth_syscalls.h"


TestBluetoothSyscalls::TestBluetoothSyscalls(const MAUtil::String& name):
		MATest::TestCase(name)
{
}


void TestBluetoothSyscalls::test_maBtStart_devicepresent()
{
	// make sure that the device has BT
	int res = maBTStart();

	expect("DevicePresentAndEnabled");
	assert("DevicePresentAndEnabled", res > 0); // device present
}


void TestBluetoothSyscalls::onBTStarted(int err_code)
{
	assert("DevicePresentAndEnabled", err_code == MA_BT_OK); // device enabled
	runNextTestCase();
}


TESTCASE(TestDownloader)

