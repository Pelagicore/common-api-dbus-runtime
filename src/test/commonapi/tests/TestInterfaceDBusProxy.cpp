/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "TestInterfaceDBusProxy.h"

namespace commonapi {
namespace tests {

std::shared_ptr<CommonAPI::DBus::DBusProxy> createTestInterfaceDBusProxy(
                    const std::string& commonApiAddress,
                    const std::string& interfaceName,
                    const std::string& busName,
                    const std::string& objectPath,
                    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyConnection) {
    return std::make_shared<TestInterfaceDBusProxy>(commonApiAddress, interfaceName, busName, objectPath, dbusProxyConnection);
}

__attribute__((constructor)) void registerTestInterfaceDBusProxy(void) {
    CommonAPI::DBus::DBusFactory::registerProxyFactoryMethod(TestInterface::getInterfaceId(),
       &createTestInterfaceDBusProxy);
}

TestInterfaceDBusProxy::TestInterfaceDBusProxy(
                    const std::string& commonApiAddress,
                    const std::string& interfaceName,
                    const std::string& busName,
                    const std::string& objectPath,
                    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyconnection):
        CommonAPI::DBus::DBusProxy(commonApiAddress, interfaceName, busName, objectPath, dbusProxyconnection)
,        testPredefinedTypeAttribute_(*this, "onTestPredefinedTypeAttributeAttributeChanged", "setTestPredefinedTypeAttributeAttribute", "u", "getTestPredefinedTypeAttributeAttribute"),
        testDerivedStructAttribute_(*this, "onTestDerivedStructAttributeAttributeChanged", "setTestDerivedStructAttributeAttribute", "(sqi)", "getTestDerivedStructAttributeAttribute"),
        testDerivedArrayAttribute_(*this, "onTestDerivedArrayAttributeAttributeChanged", "setTestDerivedArrayAttributeAttribute", "at", "getTestDerivedArrayAttributeAttribute")
,        testPredefinedTypeBroadcast_(*this, "TestPredefinedTypeBroadcast", "us")
                 {
}

TestInterfaceDBusProxy::TestPredefinedTypeAttributeAttribute& TestInterfaceDBusProxy::getTestPredefinedTypeAttributeAttribute() {
    return testPredefinedTypeAttribute_;
}
TestInterfaceDBusProxy::TestDerivedStructAttributeAttribute& TestInterfaceDBusProxy::getTestDerivedStructAttributeAttribute() {
    return testDerivedStructAttribute_;
}
TestInterfaceDBusProxy::TestDerivedArrayAttributeAttribute& TestInterfaceDBusProxy::getTestDerivedArrayAttributeAttribute() {
    return testDerivedArrayAttribute_;
}

TestInterfaceDBusProxy::TestPredefinedTypeBroadcastEvent& TestInterfaceDBusProxy::getTestPredefinedTypeBroadcastEvent() {
    return testPredefinedTypeBroadcast_;
}

void TestInterfaceDBusProxy::testEmptyMethod(CommonAPI::CallStatus& callStatus) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<> >::callMethodWithReply(
        *this,
        "testEmptyMethod",
        "",
        callStatus
        );
}
std::future<CommonAPI::CallStatus> TestInterfaceDBusProxy::testEmptyMethodAsync(TestEmptyMethodAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<> >::callMethodAsync(
        *this,
        "testEmptyMethod",
        "",
        std::move(callback));
}
void TestInterfaceDBusProxy::testVoidPredefinedTypeMethod(const uint32_t& uint32Value, const std::string& stringValue, CommonAPI::CallStatus& callStatus) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string>,
                                     CommonAPI::DBus::DBusSerializableArguments<> >::callMethodWithReply(
        *this,
        "testVoidPredefinedTypeMethod",
        "us",
        uint32Value, stringValue, 
        callStatus
        );
}
std::future<CommonAPI::CallStatus> TestInterfaceDBusProxy::testVoidPredefinedTypeMethodAsync(const uint32_t& uint32Value, const std::string& stringValue, TestVoidPredefinedTypeMethodAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string>,
                                     CommonAPI::DBus::DBusSerializableArguments<> >::callMethodAsync(
        *this,
        "testVoidPredefinedTypeMethod",
        "us",
        uint32Value, stringValue, 
        std::move(callback));
}
void TestInterfaceDBusProxy::testPredefinedTypeMethod(const uint32_t& uint32InValue, const std::string& stringInValue, CommonAPI::CallStatus& callStatus, uint32_t& uint32OutValue, std::string& stringOutValue) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string>,
                                     CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string> >::callMethodWithReply(
        *this,
        "testPredefinedTypeMethod",
        "us",
        uint32InValue, stringInValue, 
        callStatus
        , uint32OutValue, stringOutValue);
}
std::future<CommonAPI::CallStatus> TestInterfaceDBusProxy::testPredefinedTypeMethodAsync(const uint32_t& uint32InValue, const std::string& stringInValue, TestPredefinedTypeMethodAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string>,
                                     CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string> >::callMethodAsync(
        *this,
        "testPredefinedTypeMethod",
        "us",
        uint32InValue, stringInValue, 
        std::move(callback));
}
void TestInterfaceDBusProxy::testVoidDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, CommonAPI::CallStatus& callStatus) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
                                     CommonAPI::DBus::DBusSerializableArguments<> >::callMethodWithReply(
        *this,
        "testVoidDerivedTypeMethod",
        "ia{ua(sq)}",
        testEnumExtended2Value, testMapValue, 
        callStatus
        );
}
std::future<CommonAPI::CallStatus> TestInterfaceDBusProxy::testVoidDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, TestVoidDerivedTypeMethodAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
                                     CommonAPI::DBus::DBusSerializableArguments<> >::callMethodAsync(
        *this,
        "testVoidDerivedTypeMethod",
        "ia{ua(sq)}",
        testEnumExtended2Value, testMapValue, 
        std::move(callback));
}
void TestInterfaceDBusProxy::testDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, CommonAPI::CallStatus& callStatus, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
                                     CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap> >::callMethodWithReply(
        *this,
        "testDerivedTypeMethod",
        "ia{ua(sq)}",
        testEnumExtended2InValue, testMapInValue, 
        callStatus
        , testEnumExtended2OutValue, testMapOutValue);
}
std::future<CommonAPI::CallStatus> TestInterfaceDBusProxy::testDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, TestDerivedTypeMethodAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
                                     CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap> >::callMethodAsync(
        *this,
        "testDerivedTypeMethod",
        "ia{ua(sq)}",
        testEnumExtended2InValue, testMapInValue, 
        std::move(callback));
}

void TestInterfaceDBusProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

} // namespace tests
} // namespace commonapi
