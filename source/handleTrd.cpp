//
// Created by Robertkun on 2018/2/23 0023.
//

#include "../include/handleTrd.h"
#include "../include/sendMgr.h"

extern CSendMgr gSendMgr;
CHandleTrd::CHandleTrd() {

}

CHandleTrd::~CHandleTrd() {

}

void CHandleTrd::handle_loop() {
	//printf("handle thread working. thread id=[%ld]\n", mTrdID);
	char logPath[] = "./output.log";
	printf("read log : %s\n", logPath);

	std::ifstream fin(logPath);
	std::string strLine;
	while (getline(fin, strLine)) {
		//printf("strLine=%s length=%d\n", strLine.c_str(), strLine.length());
		//fflush(stdout);

		if(strLine.length() <= 0) {
			continue;
		}

		gSendMgr.put_one_msg(strLine);
	}

	fin.close();
}

void *trd_handle(void *arg)
{
	CHandleTrd *pEntity = (CHandleTrd *) arg;
	while (!pEntity->mStopTrd) {
		pEntity->handle_loop();
		usleep(10000);
	}

	return arg;
}

bool CHandleTrd::handle_start() {
	mStopTrd = false;
	if (pthread_create(&mTrdID, NULL, trd_handle, this) != 0) {
		printf("create handle thread failed!");
		return false;
	}

	printf("start handle thread = %lu !", mTrdID);
	return true;
}

void CHandleTrd::handle_stop() {
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