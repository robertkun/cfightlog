//
// Created by robertkun on 2018/2/23 0023.
//

#ifndef CMULTITHREADDEMO_SENDTRD_H
#define CMULTITHREADDEMO_SENDTRD_H

#include "com.h"

class CSendTrd {
public:
	CSendTrd();
	~CSendTrd();

	bool send_start();
	void send_stop();
	void send_loop();

public:
	bool mStopTrd;

private:
	pthread_t mTrdID;
};


#endif //CMULTITHREADDEMO_SENDTRD_H
