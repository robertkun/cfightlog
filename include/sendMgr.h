//
// Created by robertkun on 2018/2/23 0023.
//

#ifndef CMULTITHREADDEMO_SENDMGR_H
#define CMULTITHREADDEMO_SENDMGR_H

//#include "../include/com.h"
#include "../include/sendTrd.h"

class CSendMgr {
public:
	CSendMgr();
	~CSendMgr();

	bool begin_pool(int nTrdNum);
	bool end_pool();

	void put_one_msg(std::string msg);
	std::string get_one_msg();

private:
	int mnTrdNum;
	CSendTrd* mpSendArr;
	std::vector<std::string> mVecMsg;
	pthread_mutex_t mMutex;
};

extern CSendMgr gSendMgr;
#endif //CMULTITHREADDEMO_SENDMGR_H
