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
 */

#ifndef ANDROID_KF_SERVICE_H
#define ANDROID_KF_SERVICE_H

#include <utils/Errors.h>
#include <utils/String8.h>
#include <utils/String16.h>
#include <utils/Mutex.h>
#include "IBbtManagerService.h"

namespace android {
// ----------------------------------------------------------------------------

class BbtManagerService: public BnBbtManagerService
{
public:

    BbtManagerService();
    virtual ~BbtManagerService();

    virtual int32_t add(int32_t a, int32_t b);
	virtual int32_t setLedStatus(int32_t eye_up, int32_t eye_down, int32_t mouth, int32_t ear);
    static void instantiate();

private:

    int mLogLevel;
};

// ----------------------------------------------------------------------------

} // namespace android
#endif // ANDROID_SYSTEM_CONTROL_H
