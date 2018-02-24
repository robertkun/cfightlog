//
// Created by Robertkun on 2018/2/23 0023.
//

#include "../include/sendMgr.h"
using namespace std;

CSendMgr gSendMgr;
CSendMgr::CSendMgr() {
	mnTrdNum = 0;
	mpSendArr = NULL;
	pthread_mutex_init(&mMutex, NULL);
}

CSendMgr::~CSendMgr() {
	pthread_mutex_destroy(&mMutex);
}

bool CSendMgr::begin_pool(int nTrdNum) {
	mnTrdNum = nTrdNum;
	mpSendArr = new CSendTrd[nTrdNum];
	for (int i=0; i<nTrdNum; ++i) {
		mpSendArr[i].send_start();
	}

	return true;
}

bool CSendMgr::end_pool() {
	if(mpSendArr == NULL) {
		return false;
	}

	for (int i=0; i<mnTrdNum; ++i) {
		mpSendArr[i].send_start();
	}

	return true;
}

void CSendMgr::put_one_msg(std::string msg) {
	pthread_mutex_lock(&mMutex);
	mVecMsg.push_back(msg);
	pthread_mutex_unlock(&mMutex);
}

std::string CSendMgr::get_one_msg() {
	pthread_mutex_lock(&mMutex);
	std::string strMsg;
	vector<string>::iterator it = mVecMsg.begin();
	if(it != mVecMsg.end()) {
		strMsg = *it;
		mVecMsg.erase(it);
	} else {
		pthread_mutex_unlock(&mMutex);
		return string("");
	}

	pthread_mutex_unlock(&mMutex);
	return strMsg;
}