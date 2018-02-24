#include <iostream>
#include "../include/cfg.h"
#include "../include/sendMgr.h"
#include "../include/handleTrd.h"

using namespace std;

int main() {
	cout << "C Fight Log" << endl;

	STRUCT_FILE_CFG fCfg;
	readConfig(fCfg);

	CHandleTrd handle;
	handle.handle_start();
	gSendMgr.begin_pool(3);

	while(true) {
		printf("master process waiting...\n");
		sleep(10);
	}

	gSendMgr.end_pool();
	return 0;
}