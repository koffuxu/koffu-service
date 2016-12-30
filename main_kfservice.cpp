#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include <linux/capability.h>
#include <sys/prctl.h>

#include <stdio.h>
#include <stdlib.h>
#include "KfService.h"

using namespace android;

int main(int argc, char** argv)
{
    sp<ProcessState> proc(ProcessState::self());
    //sp<IServiceManager> sm = defaultServiceManager();
    //ALOGD("ServiceManager:%p",sm.get());
    KfService::instantiate();
    ALOGD("KfService run !\n");
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}

