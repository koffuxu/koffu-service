/*************************************************************************
    > File Name: BbtManagerService.cpp
    > Author: koffuxu
    > Mail: koffuxu@gmail.com 
    > Created Time: 2016年12月26日 星期一 16时20分54秒
 ************************************************************************/

#define LOG_TAG "libbbtmanagerservice"
#define LOG_NDEBUG 0

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/poll.h>

#include <utils/Log.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>
#include <sys/types.h>
#include "BbtManagerService.h"

#define SYS_LED_STATUS "/sys/devices/bus/1100f000.i2c/i2c-3/3-0064/cust_leds"
#define VALUE_MAX 7

namespace android {

void  BbtManagerService::instantiate() {
    defaultServiceManager()->addService(String16("bbtmanager"), new BbtManagerService());
    ALOGD("Koffu Service Instantiate!");
}

BbtManagerService::BbtManagerService() 
    :mLogLevel(2){
    ALOGD("Koffu Service Constract!");
}
BbtManagerService::~BbtManagerService() {
    ALOGD("Koffu Service Destract!");
}
int32_t BbtManagerService::add(int32_t a, int32_t b) {
    ALOGD("Koffu Service Add Result:%d", a+b);
    return (a+b);
}

int32_t BbtManagerService::setLedStatus(int32_t eye_up, int32_t eye_down, int32_t mouth, int32_t ear) {
    int fd = 0;
	int ret = -1;
	char value[VALUE_MAX];
	snprintf(value, VALUE_MAX,"%d %d %d %d",eye_up, eye_down, mouth, ear);
	ALOGD("setLedStatus: %s",value);
	if((fd = open(SYS_LED_STATUS, O_RDWR)) <= 0) {
		ALOGE("open (%s) failed(%d)\n", SYS_LED_STATUS, fd);
		return -1;
	}
    ret = write(fd, value, VALUE_MAX);
	if( ret < 0) {
		ALOGE("read (%s) failed(%d)\n", SYS_LED_STATUS, ret);
		close(fd);
		return -1;
	}
	close(fd);
	return ret;
    
}

} // namespace android
