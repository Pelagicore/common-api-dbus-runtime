/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef COMMONAPI_TESTS_TEST_INTERFACE_DBUS_PROXY_H_
#define COMMONAPI_TESTS_TEST_INTERFACE_DBUS_PROXY_H_

#include <commonapi/tests/TestInterfaceProxyBase.h>
#include <CommonAPI/DBus/DBusFactory.h>
#include <CommonAPI/DBus/DBusProxy.h>
#include <CommonAPI/DBus/DBusAttribute.h>
#include <CommonAPI/DBus/DBusEvent.h>

#include <string>

namespace commonapi {
namespace tests {

class TestInterfaceDBusProxy: virtual public TestInterfaceProxyBase, virtual public CommonAPI::DBus::DBusProxy {
 public:
    TestInterfaceDBusProxy(
                    const std::string& commonApiAddress,
                    const std::string& interfaceName,
                    const std::string& busName,
                    const std::string& objectPath,
                    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyconnection);

    virtual ~TestInterfaceDBusProxy() {}

    virtual TestPredefinedTypeAttributeAttribute& getTestPredefinedTypeAttributeAttribute();
    virtual TestDerivedStructAttributeAttribute& getTestDerivedStructAttributeAttribute();
    virtual TestDerivedArrayAttributeAttribute& getTestDerivedArrayAttributeAttribute();

    virtual TestPredefinedTypeBroadcastEvent& getTestPredefinedTypeBroadcastEvent();

    virtual void testEmptyMethod(CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> testEmptyMethodAsync(TestEmptyMethodAsyncCallback callback);
    virtual void testVoidPredefinedTypeMethod(const uint32_t& uint32Value, const std::string& stringValue, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> testVoidPredefinedTypeMethodAsync(const uint32_t& uint32Value, const std::string& stringValue, TestVoidPredefinedTypeMethodAsyncCallback callback);
    virtual void testPredefinedTypeMethod(const uint32_t& uint32InValue, const std::string& stringInValue, CommonAPI::CallStatus& callStatus, uint32_t& uint32OutValue, std::string& stringOutValue);
    virtual std::future<CommonAPI::CallStatus> testPredefinedTypeMethodAsync(const uint32_t& uint32InValue, const std::string& stringInValue, TestPredefinedTypeMethodAsyncCallback callback);
    virtual void testVoidDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, CommonAPI::CallStatus& callStatus);
    virtual std::future<CommonAPI::CallStatus> testVoidDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, TestVoidDerivedTypeMethodAsyncCallback callback);
    virtual void testDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, CommonAPI::CallStatus& callStatus, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue);
    virtual std::future<CommonAPI::CallStatus> testDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, TestDerivedTypeMethodAsyncCallback callback);

    virtual void getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const;

 private:
    CommonAPI::DBus::DBusObservableAttribute<CommonAPI::DBus::DBusAttribute<TestPredefinedTypeAttributeAttribute>> testPredefinedTypeAttribute_;
    CommonAPI::DBus::DBusObservableAttribute<CommonAPI::DBus::DBusAttribute<TestDerivedStructAttributeAttribute>> testDerivedStructAttribute_;
    CommonAPI::DBus::DBusObservableAttribute<CommonAPI::DBus::DBusAttribute<TestDerivedArrayAttributeAttribute>> testDerivedArrayAttribute_;

    CommonAPI::DBus::DBusEvent<TestPredefinedTypeBroadcastEvent> testPredefinedTypeBroadcast_;
};

} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_TEST_INTERFACE_DBUS_PROXY_H_
