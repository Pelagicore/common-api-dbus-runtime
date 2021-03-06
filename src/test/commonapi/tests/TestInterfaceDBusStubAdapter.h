/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 2.1.5.qualifier.
* Used org.franca.core 0.8.10.201309262002.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef COMMONAPI_TESTS_Test_Interface_DBUS_STUB_ADAPTER_H_
#define COMMONAPI_TESTS_Test_Interface_DBUS_STUB_ADAPTER_H_

#include <commonapi/tests/TestInterfaceStub.h>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/DBus/DBusStubAdapterHelper.h>
#include <CommonAPI/DBus/DBusStubAdapter.h>
#include <CommonAPI/DBus/DBusFactory.h>
#include <CommonAPI/DBus/DBusServicePublisher.h>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace commonapi {
namespace tests {

typedef CommonAPI::DBus::DBusStubAdapterHelper<TestInterfaceStub> TestInterfaceDBusStubAdapterHelper;

class TestInterfaceDBusStubAdapterInternal: public virtual TestInterfaceStubAdapter, public TestInterfaceDBusStubAdapterHelper {
 public:
    TestInterfaceDBusStubAdapterInternal(
            const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
            const std::string& commonApiAddress,
            const std::string& dbusInterfaceName,
            const std::string& dbusBusName,
            const std::string& dbusObjectPath,
            const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusConnection,
            const std::shared_ptr<CommonAPI::StubBase>& stub);

    ~TestInterfaceDBusStubAdapterInternal();

    virtual const bool hasFreedesktopProperties();

    void fireTestPredefinedTypeAttributeAttributeChanged(const uint32_t& value);
    void fireTestDerivedStructAttributeAttributeChanged(const DerivedTypeCollection::TestStructExtended& value);
    void fireTestDerivedArrayAttributeAttributeChanged(const DerivedTypeCollection::TestArrayUInt64& value);

    void fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue);
    void fireTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientId> clientId);
    void sendTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientIdList> receivers = NULL);
    void subscribeForTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientId> clientId, bool& success);
    void unsubscribeFromTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientId> clientId);
    std::shared_ptr<CommonAPI::ClientIdList> const getSubscribersForTestSelectiveBroadcastSelective();
    void fireTestBroadcastWithOutArgsSelective(const std::shared_ptr<CommonAPI::ClientId> clientId, const uint32_t& uint32Value, const std::string& stringValue);
    void sendTestBroadcastWithOutArgsSelective(const uint32_t& uint32Value, const std::string& stringValue, const std::shared_ptr<CommonAPI::ClientIdList> receivers = NULL);
    void subscribeForTestBroadcastWithOutArgsSelective(const std::shared_ptr<CommonAPI::ClientId> clientId, bool& success);
    void unsubscribeFromTestBroadcastWithOutArgsSelective(const std::shared_ptr<CommonAPI::ClientId> clientId);
    std::shared_ptr<CommonAPI::ClientIdList> const getSubscribersForTestBroadcastWithOutArgsSelective();


    const TestInterfaceDBusStubAdapterHelper::StubDispatcherTable& getStubDispatcherTable();
    const CommonAPI::DBus::StubAttributeTable& getStubAttributeTable();

    void deactivateManagedInstances();


static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        CommonAPI::Version
        > getTestInterfaceInterfaceVersionStubDispatcher;

static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        uint32_t
        > getTestPredefinedTypeAttributeAttributeStubDispatcher;
static CommonAPI::DBus::DBusSetObservableAttributeStubDispatcher<
        TestInterfaceStub,
        uint32_t
        > setTestPredefinedTypeAttributeAttributeStubDispatcher;
static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestStructExtended
        > getTestDerivedStructAttributeAttributeStubDispatcher;
static CommonAPI::DBus::DBusSetObservableAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestStructExtended
        > setTestDerivedStructAttributeAttributeStubDispatcher;
static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestArrayUInt64
        > getTestDerivedArrayAttributeAttributeStubDispatcher;
static CommonAPI::DBus::DBusSetObservableAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestArrayUInt64
        > setTestDerivedArrayAttributeAttributeStubDispatcher;


static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<>,
    std::tuple<>
    > testEmptyMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<uint32_t, std::string>,
    std::tuple<>
    > testVoidPredefinedTypeMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<uint32_t, std::string>,
    std::tuple<uint32_t, std::string>
    > testPredefinedTypeMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
    std::tuple<>
    > testVoidDerivedTypeMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
    std::tuple<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>
    > testDerivedTypeMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<std::vector<std::shared_ptr<DerivedTypeCollection::TestPolymorphicStruct>>>,
    std::tuple<>
    > testArrayOfPolymorphicStructMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::MapIntToPolymorphic>,
    std::tuple<>
    > testMapOfPolymorphicStructMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::StructWithPolymorphicMember>,
    std::tuple<>
    > testStructWithPolymorphicMemberMethodStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::StructWithEnumKeyMap>,
    std::tuple<>
    > testStructWithEnumKeyMapMemberStubDispatcher;


static CommonAPI::DBus::DBusMethodWithReplyAdapterDispatcher<
    TestInterfaceStub,
    TestInterfaceStubAdapter,
    std::tuple<>,
    std::tuple<bool>
    > subscribeTestSelectiveBroadcastSelectiveStubDispatcher;

static CommonAPI::DBus::DBusMethodWithReplyAdapterDispatcher<
    TestInterfaceStub,
    TestInterfaceStubAdapter,
 std::tuple<>,
    std::tuple<>
    > unsubscribeTestSelectiveBroadcastSelectiveStubDispatcher;
static CommonAPI::DBus::DBusMethodWithReplyAdapterDispatcher<
    TestInterfaceStub,
    TestInterfaceStubAdapter,
    std::tuple<>,
    std::tuple<bool>
    > subscribeTestBroadcastWithOutArgsSelectiveStubDispatcher;

static CommonAPI::DBus::DBusMethodWithReplyAdapterDispatcher<
    TestInterfaceStub,
    TestInterfaceStubAdapter,
 std::tuple<>,
    std::tuple<>
    > unsubscribeTestBroadcastWithOutArgsSelectiveStubDispatcher;


 protected:
    virtual const char* getMethodsDBusIntrospectionXmlData() const;

 private:
    TestInterfaceDBusStubAdapterHelper::StubDispatcherTable stubDispatcherTable_;
    CommonAPI::DBus::StubAttributeTable stubAttributeTable_;
};

class TestInterfaceDBusStubAdapter: public TestInterfaceDBusStubAdapterInternal, public std::enable_shared_from_this<TestInterfaceDBusStubAdapter> {
public:
    TestInterfaceDBusStubAdapter(
                         const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
                         const std::string& commonApiAddress,
                         const std::string& dbusInterfaceName,
                         const std::string& dbusBusName,
                         const std::string& dbusObjectPath,
                         const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusConnection,
                         const std::shared_ptr<CommonAPI::StubBase>& stub) :
            CommonAPI::DBus::DBusStubAdapter(
                            factory,
                            commonApiAddress,
                            dbusInterfaceName,
                            dbusBusName,
                            dbusObjectPath,
                            dbusConnection,
                            false),
            TestInterfaceDBusStubAdapterInternal(
                            factory,
                            commonApiAddress,
                            dbusInterfaceName,
                            dbusBusName,
                            dbusObjectPath,
                            dbusConnection,
                            stub) { }
};

} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_Test_Interface_DBUS_STUB_ADAPTER_H_
