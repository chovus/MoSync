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

	// pure virtual from TestCase
	void start();

	/*
	 * int maBTStart() - asynchronous
	 * 			 get a handler to the BT device (if exists) and enable the BT
	 * return:   0 if the device doesn't have a BT and >0 for success (the handler)
	 * callback: void onBTStarted(int err_code)
	 */
	void test_maBtStart_devicepresent();
	void test_maBtStart_nodevice();

	/*
	 * int maBtGetPairedDevices()
	 * 			Android keeps internally such list
	 */
	void test_maBtGetPairedDevices_success();

	/*
	 * int maBtStartDeviceDiscovery(in int names) - old syscall
	 * 	   		set names to non-zero to retrieve the names of remote devices.
	 * 			This takes extra time, so set it to zero for faster scanning.
	 *
	 * return: 0 on success, < 0 on failure
	 * 		DEPRECATE?
	 */


	/*
	 * int maBtCancelDiscovery()   -  asynchronous
	 * 			cancel any active discovery operation. If an operation was canceled,
	 * 			its last BT event will have the state #CONNERR_CANCELED.
	 * 			If this function returns 1, it is not safe to start another discovery before
	 * 			you've received the #CONNERR_CANCELED event.
	 * return: 0 if there was no active operation, 1 if there was.
	 * 		DEPRECATE?
	 */


	/*
	 * int maBtGetNewDevice(out MABtDevice d)
	 *      DEPRECATE?
	 */


	/*
	 * int maBtStartServiceDiscovery(in MABtAddr address, in MAUUID uuid);
	 * 		DEPRECATE?
	 */

	/*
	 * int maBtGetNextServiceSize(out MABtServiceSize dst)
	 * 		DEPRECATE?
	 */

	/*
	 * int maBtGetNewService(out MABtService dst)
	 * 		DEPRECATE?
	 *
	 */

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
