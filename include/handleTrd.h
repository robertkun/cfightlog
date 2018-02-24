//
// Created by robertkun on 2018/2/23 0023.
//

#ifndef CMULTITHREADDEMO_HANDLETRD_H
#define CMULTITHREADDEMO_HANDLETRD_H

#include "com.h"

class CHandleTrd {
public:
	CHandleTrd();
	~CHandleTrd();

	bool handle_start();
	void handle_stop();
	void handle_loop();

public:
	bool mStopTrd;

private:
	pthread_t mTrdID;
};


#endif //CMULTITHREADDEMO_HANDLETRD_H
