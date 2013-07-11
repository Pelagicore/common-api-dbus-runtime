/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef COMMONAPI_TESTS_TEST_INTERFACE_STUB_H_
#define COMMONAPI_TESTS_TEST_INTERFACE_STUB_H_

#include <unordered_map>
#include <cstdint>
#include <commonapi/tests/DerivedTypeCollection.h>
#include <CommonAPI/InputStream.h>
#include <vector>
#include <CommonAPI/OutputStream.h>
#include "TestInterface.h"
#include <CommonAPI/Stub.h>

namespace commonapi {
namespace tests {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service TestInterface. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class TestInterfaceStubAdapter: virtual public CommonAPI::StubAdapter, public TestInterface {
 public:
    ///Notifies all remote listeners about a change of value of the attribute TestPredefinedTypeAttribute.
    virtual void fireTestPredefinedTypeAttributeAttributeChanged(const uint32_t& TestPredefinedTypeAttribute) = 0;
    ///Notifies all remote listeners about a change of value of the attribute TestDerivedStructAttribute.
    virtual void fireTestDerivedStructAttributeAttributeChanged(const DerivedTypeCollection::TestStructExtended& TestDerivedStructAttribute) = 0;
    ///Notifies all remote listeners about a change of value of the attribute TestDerivedArrayAttribute.
    virtual void fireTestDerivedArrayAttributeAttributeChanged(const DerivedTypeCollection::TestArrayUInt64& TestDerivedArrayAttribute) = 0;

    /**
     * Sends a broadcast event for TestPredefinedTypeBroadcast. Should not be called directly.
     * Instead, the "fire<broadcastName>Event" methods of the stub should be used.
     */
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue) = 0;
};


/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for TestInterface.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class TestInterfaceStubRemoteEvent {
 public:
    virtual ~TestInterfaceStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute TestPredefinedTypeAttribute.
    virtual bool onRemoteSetTestPredefinedTypeAttributeAttribute(uint32_t TestPredefinedTypeAttribute) = 0;
    /// Action callback for remote set requests on the attribute TestPredefinedTypeAttribute.
    virtual void onRemoteTestPredefinedTypeAttributeAttributeChanged() = 0;

    /// Verification callback for remote set requests on the attribute TestDerivedStructAttribute.
    virtual bool onRemoteSetTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended TestDerivedStructAttribute) = 0;
    /// Action callback for remote set requests on the attribute TestDerivedStructAttribute.
    virtual void onRemoteTestDerivedStructAttributeAttributeChanged() = 0;

    /// Verification callback for remote set requests on the attribute TestDerivedArrayAttribute.
    virtual bool onRemoteSetTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 TestDerivedArrayAttribute) = 0;
    /// Action callback for remote set requests on the attribute TestDerivedArrayAttribute.
    virtual void onRemoteTestDerivedArrayAttributeAttributeChanged() = 0;

};


/**
 * Defines the interface that must be implemented by any class that should provide
 * the service TestInterface to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class TestInterfaceStub : public CommonAPI::Stub<TestInterfaceStubAdapter , TestInterfaceStubRemoteEvent> {
 public:
    virtual ~TestInterfaceStub() { }

    /// Provides getter access to the attribute TestPredefinedTypeAttribute.
    virtual const uint32_t& getTestPredefinedTypeAttributeAttribute() = 0;
    /// Provides getter access to the attribute TestDerivedStructAttribute.
    virtual const DerivedTypeCollection::TestStructExtended& getTestDerivedStructAttributeAttribute() = 0;
    /// Provides getter access to the attribute TestDerivedArrayAttribute.
    virtual const DerivedTypeCollection::TestArrayUInt64& getTestDerivedArrayAttributeAttribute() = 0;

    /// This is the method that will be called on remote calls on the method testEmptyMethod.
    virtual void testEmptyMethod() = 0;
    /// This is the method that will be called on remote calls on the method testVoidPredefinedTypeMethod.
    virtual void testVoidPredefinedTypeMethod(uint32_t uint32Value, std::string stringValue) = 0;
    /// This is the method that will be called on remote calls on the method testPredefinedTypeMethod.
    virtual void testPredefinedTypeMethod(uint32_t uint32InValue, std::string stringInValue, uint32_t& uint32OutValue, std::string& stringOutValue) = 0;
    /// This is the method that will be called on remote calls on the method testVoidDerivedTypeMethod.
    virtual void testVoidDerivedTypeMethod(DerivedTypeCollection::TestEnumExtended2 testEnumExtended2Value, DerivedTypeCollection::TestMap testMapValue) = 0;
    /// This is the method that will be called on remote calls on the method testDerivedTypeMethod.
    virtual void testDerivedTypeMethod(DerivedTypeCollection::TestEnumExtended2 testEnumExtended2InValue, DerivedTypeCollection::TestMap testMapInValue, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue) = 0;
    
    /// Sends a broadcast event for TestPredefinedTypeBroadcast.
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue) = 0;
};

} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_TEST_INTERFACE_STUB_H_
