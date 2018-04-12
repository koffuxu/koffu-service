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
 *  - 1 control system sysfs proc env & property
 */

#ifndef ANDROID_IBBTMANAGERSERVICE_H
#define ANDROID_IBBTMANAGERSERVICE_H

#include <utils/Errors.h>
#include <binder/IInterface.h>
#include <utils/String8.h>
#include <utils/String16.h>

namespace android {

enum {
    GET_ADD_RESULT      = IBinder::FIRST_CALL_TRANSACTION,
    SET_LED_STAT      	= IBinder::FIRST_CALL_TRANSACTION + 1,
};

class IBbtManagerService : public IInterface
{
public:
    DECLARE_META_INTERFACE(BbtManagerService);

    virtual int32_t add(int32_t a, int32_t b) = 0;
	virtual int32_t setLedStatus(int32_t a, int32_t b, int32_t c, int32_t d) = 0;
};

// ----------------------------------------------------------------------------
class BnBbtManagerService: public BnInterface<IBbtManagerService> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_ISYSTEMCONTROLSERVICE_H
