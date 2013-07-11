/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "TestInterfaceDBusStubAdapter.h"
#include <commonapi/tests/TestInterface.h>

namespace commonapi {
namespace tests {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createTestInterfaceDBusStubAdapter(
                   const std::string& commonApiAddress,
                   const std::string& interfaceName,
                   const std::string& busName,
                   const std::string& objectPath,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyConnection,
                   const std::shared_ptr<CommonAPI::StubBase>& stubBase) {
    return std::make_shared<TestInterfaceDBusStubAdapter>(commonApiAddress, interfaceName, busName, objectPath, dbusProxyConnection, stubBase);
}

__attribute__((constructor)) void registerTestInterfaceDBusStubAdapter(void) {
    CommonAPI::DBus::DBusFactory::registerAdapterFactoryMethod(TestInterface::getInterfaceId(),
                                                               &createTestInterfaceDBusStubAdapter);
}

TestInterfaceDBusStubAdapter::TestInterfaceDBusStubAdapter(
        const std::string& commonApiAddress,
        const std::string& dbusInterfaceName,
        const std::string& dbusBusName,
        const std::string& dbusObjectPath,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusConnection,
        const std::shared_ptr<CommonAPI::StubBase>& stub):
        TestInterfaceDBusStubAdapterHelper(commonApiAddress, dbusInterfaceName, dbusBusName, dbusObjectPath, dbusConnection, std::dynamic_pointer_cast<TestInterfaceStub>(stub)) {
}

const char* TestInterfaceDBusStubAdapter::getMethodsDBusIntrospectionXmlData() const {
    return
        "<method name=\"getTestPredefinedTypeAttributeAttribute\">\n"
        	"<arg name=\"value\" type=\"u\" direction=\"out\" />"
        "</method>\n"
        "<method name=\"setTestPredefinedTypeAttributeAttribute\">\n"
            "<arg name=\"requestedValue\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"setValue\" type=\"u\" direction=\"out\" />\n"
        "</method>\n"
        "<signal name=\"onTestPredefinedTypeAttributeAttributeChanged\">\n"
            "<arg name=\"changedValue\" type=\"u\" />\n"
        "</signal>\n"
        "<method name=\"getTestDerivedStructAttributeAttribute\">\n"
        	"<arg name=\"value\" type=\"(sqi)\" direction=\"out\" />"
        "</method>\n"
        "<method name=\"setTestDerivedStructAttributeAttribute\">\n"
            "<arg name=\"requestedValue\" type=\"(sqi)\" direction=\"in\" />\n"
            "<arg name=\"setValue\" type=\"(sqi)\" direction=\"out\" />\n"
        "</method>\n"
        "<signal name=\"onTestDerivedStructAttributeAttributeChanged\">\n"
            "<arg name=\"changedValue\" type=\"(sqi)\" />\n"
        "</signal>\n"
        "<method name=\"getTestDerivedArrayAttributeAttribute\">\n"
        	"<arg name=\"value\" type=\"at\" direction=\"out\" />"
        "</method>\n"
        "<method name=\"setTestDerivedArrayAttributeAttribute\">\n"
            "<arg name=\"requestedValue\" type=\"at\" direction=\"in\" />\n"
            "<arg name=\"setValue\" type=\"at\" direction=\"out\" />\n"
        "</method>\n"
        "<signal name=\"onTestDerivedArrayAttributeAttributeChanged\">\n"
            "<arg name=\"changedValue\" type=\"at\" />\n"
        "</signal>\n"
        "<signal name=\"TestPredefinedTypeBroadcast\">\n"
            "<arg name=\"uint32Value\" type=\"u\" />\n"
            "<arg name=\"stringValue\" type=\"s\" />\n"
        "</signal>\n"
        "<method name=\"testEmptyMethod\">\n"
        "</method>\n"
        "<method name=\"testVoidPredefinedTypeMethod\">\n"
            "<arg name=\"uint32Value\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"stringValue\" type=\"s\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"testPredefinedTypeMethod\">\n"
            "<arg name=\"uint32InValue\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"stringInValue\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"uint32OutValue\" type=\"u\" direction=\"out\" />\n"
            "<arg name=\"stringOutValue\" type=\"s\" direction=\"out\" />\n"
        "</method>\n"
        "<method name=\"testVoidDerivedTypeMethod\">\n"
            "<arg name=\"testEnumExtended2Value\" type=\"i\" direction=\"in\" />\n"
            "<arg name=\"testMapValue\" type=\"a{ua(sq)}\" direction=\"in\" />\n"
        "</method>\n"
        "<method name=\"testDerivedTypeMethod\">\n"
            "<arg name=\"testEnumExtended2InValue\" type=\"i\" direction=\"in\" />\n"
            "<arg name=\"testMapInValue\" type=\"a{ua(sq)}\" direction=\"in\" />\n"
            "<arg name=\"testEnumExtended2OutValue\" type=\"i\" direction=\"out\" />\n"
            "<arg name=\"testMapOutValue\" type=\"a{ua(sq)}\" direction=\"out\" />\n"
        "</method>\n"
    ;
}


static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        uint32_t
        > getTestPredefinedTypeAttributeAttributeStubDispatcher(&TestInterfaceStub::getTestPredefinedTypeAttributeAttribute, "u");
static CommonAPI::DBus::DBusSetObservableAttributeStubDispatcher<
        TestInterfaceStub,
        uint32_t
        > setTestPredefinedTypeAttributeAttributeStubDispatcher(
                &TestInterfaceStub::getTestPredefinedTypeAttributeAttribute,
                &TestInterfaceStubRemoteEvent::onRemoteSetTestPredefinedTypeAttributeAttribute,
                &TestInterfaceStubRemoteEvent::onRemoteTestPredefinedTypeAttributeAttributeChanged,
                &TestInterfaceStubAdapter::fireTestPredefinedTypeAttributeAttributeChanged,
                "u");

static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestStructExtended
        > getTestDerivedStructAttributeAttributeStubDispatcher(&TestInterfaceStub::getTestDerivedStructAttributeAttribute, "(sqi)");
static CommonAPI::DBus::DBusSetObservableAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestStructExtended
        > setTestDerivedStructAttributeAttributeStubDispatcher(
                &TestInterfaceStub::getTestDerivedStructAttributeAttribute,
                &TestInterfaceStubRemoteEvent::onRemoteSetTestDerivedStructAttributeAttribute,
                &TestInterfaceStubRemoteEvent::onRemoteTestDerivedStructAttributeAttributeChanged,
                &TestInterfaceStubAdapter::fireTestDerivedStructAttributeAttributeChanged,
                "(sqi)");

static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestArrayUInt64
        > getTestDerivedArrayAttributeAttributeStubDispatcher(&TestInterfaceStub::getTestDerivedArrayAttributeAttribute, "at");
static CommonAPI::DBus::DBusSetObservableAttributeStubDispatcher<
        TestInterfaceStub,
        DerivedTypeCollection::TestArrayUInt64
        > setTestDerivedArrayAttributeAttributeStubDispatcher(
                &TestInterfaceStub::getTestDerivedArrayAttributeAttribute,
                &TestInterfaceStubRemoteEvent::onRemoteSetTestDerivedArrayAttributeAttribute,
                &TestInterfaceStubRemoteEvent::onRemoteTestDerivedArrayAttributeAttributeChanged,
                &TestInterfaceStubAdapter::fireTestDerivedArrayAttributeAttributeChanged,
                "at");


static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<>,
    std::tuple<>
    > testEmptyMethodStubDispatcher(&TestInterfaceStub::testEmptyMethod, "");

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<uint32_t, std::string>,
    std::tuple<>
    > testVoidPredefinedTypeMethodStubDispatcher(&TestInterfaceStub::testVoidPredefinedTypeMethod, "");

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<uint32_t, std::string>,
    std::tuple<uint32_t, std::string>
    > testPredefinedTypeMethodStubDispatcher(&TestInterfaceStub::testPredefinedTypeMethod, "us");

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
    std::tuple<>
    > testVoidDerivedTypeMethodStubDispatcher(&TestInterfaceStub::testVoidDerivedTypeMethod, "");

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    TestInterfaceStub,
    std::tuple<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>,
    std::tuple<DerivedTypeCollection::TestEnumExtended2, DerivedTypeCollection::TestMap>
    > testDerivedTypeMethodStubDispatcher(&TestInterfaceStub::testDerivedTypeMethod, "ia{ua(sq)}");


template<>
const TestInterfaceDBusStubAdapterHelper::StubDispatcherTable TestInterfaceDBusStubAdapterHelper::stubDispatcherTable_ = {
    { { "getTestPredefinedTypeAttributeAttribute", "" }, &commonapi::tests::getTestPredefinedTypeAttributeAttributeStubDispatcher }
    , { { "setTestPredefinedTypeAttributeAttribute", "u" }, &commonapi::tests::setTestPredefinedTypeAttributeAttributeStubDispatcher },
    { { "getTestDerivedStructAttributeAttribute", "" }, &commonapi::tests::getTestDerivedStructAttributeAttributeStubDispatcher }
    , { { "setTestDerivedStructAttributeAttribute", "(sqi)" }, &commonapi::tests::setTestDerivedStructAttributeAttributeStubDispatcher },
    { { "getTestDerivedArrayAttributeAttribute", "" }, &commonapi::tests::getTestDerivedArrayAttributeAttributeStubDispatcher }
    , { { "setTestDerivedArrayAttributeAttribute", "at" }, &commonapi::tests::setTestDerivedArrayAttributeAttributeStubDispatcher }
    ,
    { { "testEmptyMethod", "" }, &commonapi::tests::testEmptyMethodStubDispatcher },
    { { "testVoidPredefinedTypeMethod", "us" }, &commonapi::tests::testVoidPredefinedTypeMethodStubDispatcher },
    { { "testPredefinedTypeMethod", "us" }, &commonapi::tests::testPredefinedTypeMethodStubDispatcher },
    { { "testVoidDerivedTypeMethod", "ia{ua(sq)}" }, &commonapi::tests::testVoidDerivedTypeMethodStubDispatcher },
    { { "testDerivedTypeMethod", "ia{ua(sq)}" }, &commonapi::tests::testDerivedTypeMethodStubDispatcher }
};

void TestInterfaceDBusStubAdapter::fireTestPredefinedTypeAttributeAttributeChanged(const uint32_t& value) {
	CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<uint32_t>>
        ::sendSignal(
            *this,
            "onTestPredefinedTypeAttributeAttributeChanged",
            "u",
            value
    );
}
void TestInterfaceDBusStubAdapter::fireTestDerivedStructAttributeAttributeChanged(const DerivedTypeCollection::TestStructExtended& value) {
	CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestStructExtended>>
        ::sendSignal(
            *this,
            "onTestDerivedStructAttributeAttributeChanged",
            "(sqi)",
            value
    );
}
void TestInterfaceDBusStubAdapter::fireTestDerivedArrayAttributeAttributeChanged(const DerivedTypeCollection::TestArrayUInt64& value) {
	CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<DerivedTypeCollection::TestArrayUInt64>>
        ::sendSignal(
            *this,
            "onTestDerivedArrayAttributeAttributeChanged",
            "at",
            value
    );
}

void TestInterfaceDBusStubAdapter::fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue) {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<uint32_t, std::string>>
            ::sendSignal(
                *this,
                "TestPredefinedTypeBroadcast",
                "us",
                uint32Value, stringValue
        );
}

} // namespace tests
} // namespace commonapi
