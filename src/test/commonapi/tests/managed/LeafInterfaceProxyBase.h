/*
* This file was generated by the CommonAPI Generators. 
* Used org.genivi.commonapi.core 2.1.3.qualifier.
* Used org.franca.core 0.8.10.201309262002.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef COMMONAPI_TESTS_MANAGED_Leaf_Interface_PROXY_BASE_H_
#define COMMONAPI_TESTS_MANAGED_Leaf_Interface_PROXY_BASE_H_

#include "LeafInterface.h"



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif


#include <CommonAPI/Proxy.h>
#include <functional>
#include <future>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace commonapi {
namespace tests {
namespace managed {

class LeafInterfaceProxyBase: virtual public CommonAPI::Proxy {
 public:

    typedef std::function<void(const CommonAPI::CallStatus&, const LeafInterface::testLeafMethodError&, const int32_t&, const std::string&)> TestLeafMethodAsyncCallback;



    virtual void testLeafMethod(const int32_t& inInt, const std::string& inString, CommonAPI::CallStatus& callStatus, LeafInterface::testLeafMethodError& methodError, int32_t& outInt, std::string& outString) = 0;
    virtual std::future<CommonAPI::CallStatus> testLeafMethodAsync(const int32_t& inInt, const std::string& inString, TestLeafMethodAsyncCallback callback) = 0;
};

} // namespace managed
} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_MANAGED_Leaf_Interface_PROXY_BASE_H_
