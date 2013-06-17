/*
 * test_bluetooth_syscalls.h
 *
 *  Created on: Jun 17, 2013
 *      Author: ovidel
 */

#ifndef TEST_BLUETOOTH_SYSCALLS_H_
#define TEST_BLUETOOTH_SYSCALLS_H_


#include "TestRunner.h"


class TestBluetoothSyscalls:
		public MATest::TestCase
{
public:
	TestBluetoothSyscalls(const MAUtil::String& name);

	/*
	 * sysc all: int maBTStart() - asynchronous
	 * get a handler to the BT device (if exists) and enable the BT
	 * return:   0 if the device doesn't have a BT and >0 for success (the handler)
	 * callback: void onBTStarted(int err_code)
	 */
	void test_maBtStart_devicepresent();

private:
	/*
	 * call-back for maBTStart()
	 *
	 * err_code: MA_BT_{OK, NOT_FOUND, NOT_ENABLED}
	 */
	void onBTStarted(int err_code);

private:
	MAHandler mBTHandler;
};

#endif /* TEST_BLUETOOTH_SYSCALLS_H_ */
