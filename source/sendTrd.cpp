//
// Created by Administrator on 2018/2/23 0023.
//

#include "../include/sendTrd.h"
#include "../include/sendMgr.h"
#include "../include/curl.h"

extern CSendMgr gSendMgr;

CSendTrd::CSendTrd() {

}

CSendTrd::~CSendTrd() {

}

void CSendTrd::send_loop() {
	//printf("send thread working. thread id=[%ld]\n", mTrdID);
	std::string msg = gSendMgr.get_one_msg();
	if(msg.empty()) {
		return;
	}

	printf("post msg=%s\n", msg.c_str());
	http_post(msg.c_str());
}

void *trd_send(void *arg)
{
	CSendTrd *pEntity = (CSendTrd *) arg;
	while (!pEntity->mStopTrd) {
		pEntity->send_loop();
	}

	return arg;
}

void CSendTrd::send_stop()
{
	if (mTrdID == 0) {
		return;
	}

	mStopTrd = true;
	usleep(10000);
	if (mTrdID != 0) {
		pthread_join(mTrdID, NULL);
	}

	printf("send thread exit = %lu !", mTrdID);
	mTrdID = 0;
}

bool CSendTrd::send_start()
{
	mStopTrd = false;
	if (pthread_create(&mTrdID, NULL, trd_send, this) != 0) {
		printf("create send thread failed!");
		return false;
	}

	printf("start send thread = %lu !", mTrdID);
	return true;
}