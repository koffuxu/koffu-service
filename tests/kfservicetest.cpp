/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "KfService"
#define LOG_NDEBUG 0

#include <../IKfService.h>

#include <binder/Binder.h>
#include <binder/IServiceManager.h>
#include <utils/Atomic.h>
#include <utils/Log.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <utils/String16.h>

using namespace android;

class DeathNotifier: public IBinder::DeathRecipient
{
public:
    DeathNotifier() {
    }

    void binderDied(const wp<IBinder>& who) {
	    ALOGW("kfservice died!");
	}
};

int main(int argc, char** argv)
{
    sp<IServiceManager> sm = defaultServiceManager();
    if (sm == NULL) {
        ALOGE("Couldn't get default ServiceManager\n");
        return false;
    }

#if 1
    sp<IKfService> mKfService = interface_cast<IKfService>(sm->getService(String16("koffu_service")));
    if ( mKfService == NULL) {
        ALOGE("Couldn't get connection to koffu service\n");
        return -1;
    }
#endif

#if 0
	sp<DeathNotifier> mDeathNotifier;
	sp<IBinder> binder;
	binder = sm->getService(String16("system_write"));
	if (mDeathNotifier == NULL) {
        mDeathNotifier = new DeathNotifier();
    }
	binder->linkToDeath(mDeathNotifier);
	sp<ISystemControlService> mSystemWriteService = interface_cast<ISystemControlService>(binder);
	if (mSystemWriteService == NULL) {
        ALOGE("Couldn't get connection to SystemWriteService\n");
        return -1;
    }
#endif

    int32_t value;
	value = mKfService->add(8, 3);
	ALOGI("get result from KfService : %d\n", value);
    return 0;
}
