/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef COMMONAPI_TESTS_TEST_INTERFACE_STUB_DEFAULT_H_
#define COMMONAPI_TESTS_TEST_INTERFACE_STUB_DEFAULT_H_

#include <commonapi/tests/TestInterfaceStub.h>

namespace commonapi {
namespace tests {

/**
 * Provides a default implementation for TestInterfaceStubRemoteEvent and
 * TestInterfaceStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 * 
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class TestInterfaceStubDefault : public TestInterfaceStub {
 public:
    TestInterfaceStubDefault();

    TestInterfaceStubRemoteEvent* initStubAdapter(const std::shared_ptr<TestInterfaceStubAdapter>& stubAdapter);

    virtual const uint32_t& getTestPredefinedTypeAttributeAttribute();
    virtual void setTestPredefinedTypeAttributeAttribute(uint32_t value);

    virtual const DerivedTypeCollection::TestStructExtended& getTestDerivedStructAttributeAttribute();
    virtual void setTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended value);

    virtual const DerivedTypeCollection::TestArrayUInt64& getTestDerivedArrayAttributeAttribute();
    virtual void setTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 value);


    virtual void testEmptyMethod();

    virtual void testVoidPredefinedTypeMethod(uint32_t uint32Value, std::string stringValue);

    virtual void testPredefinedTypeMethod(uint32_t uint32InValue, std::string stringInValue, uint32_t& uint32OutValue, std::string& stringOutValue);

    virtual void testVoidDerivedTypeMethod(DerivedTypeCollection::TestEnumExtended2 testEnumExtended2Value, DerivedTypeCollection::TestMap testMapValue);

    virtual void testDerivedTypeMethod(DerivedTypeCollection::TestEnumExtended2 testEnumExtended2InValue, DerivedTypeCollection::TestMap testMapInValue, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue);

    
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue);

 protected:
    virtual void onRemoteTestPredefinedTypeAttributeAttributeChanged();
    virtual bool trySetTestPredefinedTypeAttributeAttribute(uint32_t value);
    virtual bool validateTestPredefinedTypeAttributeAttributeRequestedValue(const uint32_t& value);

    virtual void onRemoteTestDerivedStructAttributeAttributeChanged();
    virtual bool trySetTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended value);
    virtual bool validateTestDerivedStructAttributeAttributeRequestedValue(const DerivedTypeCollection::TestStructExtended& value);

    virtual void onRemoteTestDerivedArrayAttributeAttributeChanged();
    virtual bool trySetTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 value);
    virtual bool validateTestDerivedArrayAttributeAttributeRequestedValue(const DerivedTypeCollection::TestArrayUInt64& value);

    
 private:
    class RemoteEventHandler: public TestInterfaceStubRemoteEvent {
     public:
        RemoteEventHandler(TestInterfaceStubDefault* defaultStub);

        virtual bool onRemoteSetTestPredefinedTypeAttributeAttribute(uint32_t value);
        virtual void onRemoteTestPredefinedTypeAttributeAttributeChanged();

        virtual bool onRemoteSetTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended value);
        virtual void onRemoteTestDerivedStructAttributeAttributeChanged();

        virtual bool onRemoteSetTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 value);
        virtual void onRemoteTestDerivedArrayAttributeAttributeChanged();


     private:
        TestInterfaceStubDefault* defaultStub_;
    };

    RemoteEventHandler remoteEventHandler_;
    std::shared_ptr<TestInterfaceStubAdapter> stubAdapter_;

    uint32_t testPredefinedTypeAttributeAttributeValue_;
    DerivedTypeCollection::TestStructExtended testDerivedStructAttributeAttributeValue_;
    DerivedTypeCollection::TestArrayUInt64 testDerivedArrayAttributeAttributeValue_;
};

} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_TEST_INTERFACE_STUB_DEFAULT_H_
