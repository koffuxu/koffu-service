/*************************************************************************
    > File Name: KfService.cpp
    > Author: koffuxu
    > Mail: koffuxu@gmail.com 
    > Created Time: 2016年12月26日 星期一 16时20分54秒
 ************************************************************************/

#define LOG_TAG "KfService"
#define LOG_NDEBUG 0

#include <utils/Log.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>
#include <sys/types.h>
#include "KfService.h"

namespace android {

void  KfService::instantiate() {
    defaultServiceManager()->addService(String16("koffu_service"), new KfService());
    ALOGD("Koffu Service Instantiate!");
}

KfService::KfService() 
    :mLogLevel(2){
    ALOGD("Koffu Service Constract!");
}
KfService::~KfService() {
    ALOGD("Koffu Service Destract!");
}
int32_t KfService::add(int32_t a, int32_t b) {
    ALOGD("Koffu Service Add Result:%d", a+b);
    return (a+b);
}

} // namespace android
