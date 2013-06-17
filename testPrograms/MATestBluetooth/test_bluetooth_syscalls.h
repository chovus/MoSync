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

	void test_maBtStart_devicepresent();

private:
	// call-backs for the BT asynchronous events
	void onBTStarted(int err_code);

private:
	MAHandler mBTHandler;
};

#endif /* TEST_BLUETOOTH_SYSCALLS_H_ */
