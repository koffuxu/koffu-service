/*
 * Copyright (C) 2011 The Android Open Source Project
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
 *  @author   tellen
 *  @version  1.0
 *  @date     2013/04/26
 *  @par function description:
 *  - 1 write property or sysfs from native to java service
 */

#define LOG_TAG "KfService"
#define LOG_NDEBUG 0

#include <utils/Log.h>
#include <stdint.h>
#include <sys/types.h>
#include <binder/Parcel.h>
#include <IKfService.h>

namespace android {

class BpKfService: public BpInterface<IKfService>
{
public:
    BpKfService(const sp<IBinder>& impl)
        : BpInterface<IKfService>(impl)
    {
    }

    virtual int32_t add(int32_t a, int32_t b)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IKfService::getInterfaceDescriptor());
        data.writeInt32(a);
        data.writeInt32(b);

        if (remote()->transact(GET_ADD_RESULT, data, &reply) != NO_ERROR) {
            ALOGE("set 3d mode could not contact remote\n");
            return -1;
        }

        return reply.readInt32();
    }

};

IMPLEMENT_META_INTERFACE(KfService, "android.KfService");

// ----------------------------------------------------------------------------

status_t BnKfService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
       
        case GET_ADD_RESULT: {
            CHECK_INTERFACE(IKfService, data, reply);
            int32_t a = data.readInt32();
            int32_t b = data.readInt32();
            int result = add(a, b);
            reply->writeInt32(result);
            return NO_ERROR;
        }
      
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
    // should be unreachable
    return NO_ERROR;
}

}; // namespace android
