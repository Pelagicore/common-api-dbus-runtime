/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef COMMONAPI_TESTS_TEST_INTERFACE_PROXY_BASE_H_
#define COMMONAPI_TESTS_TEST_INTERFACE_PROXY_BASE_H_

#include "TestInterface.h"
#include <unordered_map>
#include <cstdint>
#include <commonapi/tests/DerivedTypeCollection.h>
#include <CommonAPI/InputStream.h>
#include <vector>
#include <CommonAPI/OutputStream.h>
#include <CommonAPI/Attribute.h>
#include <CommonAPI/Event.h>
#include <CommonAPI/Proxy.h>
#include <functional>
#include <future>

namespace commonapi {
namespace tests {

class TestInterfaceProxyBase: virtual public CommonAPI::Proxy {
 public:
    typedef CommonAPI::ObservableAttribute<uint32_t> TestPredefinedTypeAttributeAttribute;
    typedef CommonAPI::ObservableAttribute<DerivedTypeCollection::TestStructExtended> TestDerivedStructAttributeAttribute;
    typedef CommonAPI::ObservableAttribute<DerivedTypeCollection::TestArrayUInt64> TestDerivedArrayAttributeAttribute;
    typedef CommonAPI::Event<uint32_t, std::string> TestPredefinedTypeBroadcastEvent;
    typedef std::function<void(const CommonAPI::CallStatus&)> TestEmptyMethodAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&)> TestVoidPredefinedTypeMethodAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const uint32_t&, const std::string&)> TestPredefinedTypeMethodAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&)> TestVoidDerivedTypeMethodAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const DerivedTypeCollection::TestEnumExtended2&, const DerivedTypeCollection::TestMap&)> TestDerivedTypeMethodAsyncCallback;

    virtual TestPredefinedTypeAttributeAttribute& getTestPredefinedTypeAttributeAttribute() = 0;
    virtual TestDerivedStructAttributeAttribute& getTestDerivedStructAttributeAttribute() = 0;
    virtual TestDerivedArrayAttributeAttribute& getTestDerivedArrayAttributeAttribute() = 0;

    virtual TestPredefinedTypeBroadcastEvent& getTestPredefinedTypeBroadcastEvent() = 0;


    virtual void testEmptyMethod(CommonAPI::CallStatus& callStatus) = 0;
    virtual std::future<CommonAPI::CallStatus> testEmptyMethodAsync(TestEmptyMethodAsyncCallback callback) = 0;

    virtual void testVoidPredefinedTypeMethod(const uint32_t& uint32Value, const std::string& stringValue, CommonAPI::CallStatus& callStatus) = 0;
    virtual std::future<CommonAPI::CallStatus> testVoidPredefinedTypeMethodAsync(const uint32_t& uint32Value, const std::string& stringValue, TestVoidPredefinedTypeMethodAsyncCallback callback) = 0;

    virtual void testPredefinedTypeMethod(const uint32_t& uint32InValue, const std::string& stringInValue, CommonAPI::CallStatus& callStatus, uint32_t& uint32OutValue, std::string& stringOutValue) = 0;
    virtual std::future<CommonAPI::CallStatus> testPredefinedTypeMethodAsync(const uint32_t& uint32InValue, const std::string& stringInValue, TestPredefinedTypeMethodAsyncCallback callback) = 0;

    virtual void testVoidDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, CommonAPI::CallStatus& callStatus) = 0;
    virtual std::future<CommonAPI::CallStatus> testVoidDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, TestVoidDerivedTypeMethodAsyncCallback callback) = 0;

    virtual void testDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, CommonAPI::CallStatus& callStatus, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue) = 0;
    virtual std::future<CommonAPI::CallStatus> testDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, TestDerivedTypeMethodAsyncCallback callback) = 0;
};


} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_TEST_INTERFACE_PROXY_BASE_H_
