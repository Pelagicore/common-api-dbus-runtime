/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef COMMONAPI_TESTS_TEST_INTERFACE_PROXY_H_
#define COMMONAPI_TESTS_TEST_INTERFACE_PROXY_H_

#include "TestInterfaceProxyBase.h"
#include <CommonAPI/AttributeExtension.h>
#include <CommonAPI/Factory.h>

namespace commonapi {
namespace tests {

template <typename ... _AttributeExtensions>
class TestInterfaceProxy: virtual public TestInterface, virtual public TestInterfaceProxyBase, public _AttributeExtensions... {
 public:
    TestInterfaceProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~TestInterfaceProxy();

    /// Returns the wrapper class that provides access to the attribute TestPredefinedTypeAttribute.
    virtual TestPredefinedTypeAttributeAttribute& getTestPredefinedTypeAttributeAttribute();
    /// Returns the wrapper class that provides access to the attribute TestDerivedStructAttribute.
    virtual TestDerivedStructAttributeAttribute& getTestDerivedStructAttributeAttribute();
    /// Returns the wrapper class that provides access to the attribute TestDerivedArrayAttribute.
    virtual TestDerivedArrayAttributeAttribute& getTestDerivedArrayAttributeAttribute();

    /// Returns the wrapper class that provides access to the broadcast TestPredefinedTypeBroadcast.
    virtual TestPredefinedTypeBroadcastEvent& getTestPredefinedTypeBroadcastEvent();


    /**
     * Calls testEmptyMethod with synchronous semantics.
     * 
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     * Synchronous calls are not supported (will block indefinitely) when mainloop integration is used.
     */
    virtual void testEmptyMethod(CommonAPI::CallStatus& callStatus);
    /**
     * Calls testEmptyMethod with asynchronous semantics.
     * 
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> testEmptyMethodAsync(TestEmptyMethodAsyncCallback callback);

    /**
     * Calls testVoidPredefinedTypeMethod with synchronous semantics.
     * 
     * All const parameters are input parameters to this method.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     * Synchronous calls are not supported (will block indefinitely) when mainloop integration is used.
     */
    virtual void testVoidPredefinedTypeMethod(const uint32_t& uint32Value, const std::string& stringValue, CommonAPI::CallStatus& callStatus);
    /**
     * Calls testVoidPredefinedTypeMethod with asynchronous semantics.
     * 
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> testVoidPredefinedTypeMethodAsync(const uint32_t& uint32Value, const std::string& stringValue, TestVoidPredefinedTypeMethodAsyncCallback callback);

    /**
     * Calls testPredefinedTypeMethod with synchronous semantics.
     * 
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     * Synchronous calls are not supported (will block indefinitely) when mainloop integration is used.
     */
    virtual void testPredefinedTypeMethod(const uint32_t& uint32InValue, const std::string& stringInValue, CommonAPI::CallStatus& callStatus, uint32_t& uint32OutValue, std::string& stringOutValue);
    /**
     * Calls testPredefinedTypeMethod with asynchronous semantics.
     * 
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> testPredefinedTypeMethodAsync(const uint32_t& uint32InValue, const std::string& stringInValue, TestPredefinedTypeMethodAsyncCallback callback);

    /**
     * Calls testVoidDerivedTypeMethod with synchronous semantics.
     * 
     * All const parameters are input parameters to this method.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     * Synchronous calls are not supported (will block indefinitely) when mainloop integration is used.
     */
    virtual void testVoidDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, CommonAPI::CallStatus& callStatus);
    /**
     * Calls testVoidDerivedTypeMethod with asynchronous semantics.
     * 
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> testVoidDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, TestVoidDerivedTypeMethodAsyncCallback callback);

    /**
     * Calls testDerivedTypeMethod with synchronous semantics.
     * 
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     * Synchronous calls are not supported (will block indefinitely) when mainloop integration is used.
     */
    virtual void testDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, CommonAPI::CallStatus& callStatus, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue);
    /**
     * Calls testDerivedTypeMethod with asynchronous semantics.
     * 
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> testDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, TestDerivedTypeMethodAsyncCallback callback);

    /// Returns the CommonAPI address of the remote partner this proxy communicates with.
    virtual std::string getAddress() const;

    /// Returns the domain of the remote partner this proxy communicates with.
    virtual const std::string& getDomain() const;

    /// Returns the service ID of the remote partner this proxy communicates with.
    virtual const std::string& getServiceId() const;

    /// Returns the instance ID of the remote partner this proxy communicates with.
    virtual const std::string& getInstanceId() const;

    /// Returns true if the remote partner for this proxy is available.
    virtual bool isAvailable() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

 private:
    std::shared_ptr<TestInterfaceProxyBase> delegate_;
};

namespace TestInterfaceExtensions {
    template <template <typename > class _ExtensionType>
    class TestPredefinedTypeAttributeAttributeExtension {
     public:
        typedef _ExtensionType<TestInterfaceProxyBase::TestPredefinedTypeAttributeAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension<TestInterfaceProxyBase::TestPredefinedTypeAttributeAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        TestPredefinedTypeAttributeAttributeExtension(TestInterfaceProxyBase& proxy): attributeExtension_(proxy.getTestPredefinedTypeAttributeAttribute()) {
        }
    
        inline extension_type& getTestPredefinedTypeAttributeAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

    template <template <typename > class _ExtensionType>
    class TestDerivedStructAttributeAttributeExtension {
     public:
        typedef _ExtensionType<TestInterfaceProxyBase::TestDerivedStructAttributeAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension<TestInterfaceProxyBase::TestDerivedStructAttributeAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        TestDerivedStructAttributeAttributeExtension(TestInterfaceProxyBase& proxy): attributeExtension_(proxy.getTestDerivedStructAttributeAttribute()) {
        }
    
        inline extension_type& getTestDerivedStructAttributeAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

    template <template <typename > class _ExtensionType>
    class TestDerivedArrayAttributeAttributeExtension {
     public:
        typedef _ExtensionType<TestInterfaceProxyBase::TestDerivedArrayAttributeAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension<TestInterfaceProxyBase::TestDerivedArrayAttributeAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        TestDerivedArrayAttributeAttributeExtension(TestInterfaceProxyBase& proxy): attributeExtension_(proxy.getTestDerivedArrayAttributeAttribute()) {
        }
    
        inline extension_type& getTestDerivedArrayAttributeAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

} // namespace TestInterfaceExtensions

//
// TestInterfaceProxy Implementation
//
template <typename ... _AttributeExtensions>
TestInterfaceProxy<_AttributeExtensions...>::TestInterfaceProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        delegate_(std::dynamic_pointer_cast<TestInterfaceProxyBase>(delegate)),
        _AttributeExtensions(*(std::dynamic_pointer_cast<TestInterfaceProxyBase>(delegate)))... {
}

template <typename ... _AttributeExtensions>
TestInterfaceProxy<_AttributeExtensions...>::~TestInterfaceProxy() {
}

template <typename ... _AttributeExtensions>
typename TestInterfaceProxy<_AttributeExtensions...>::TestPredefinedTypeAttributeAttribute& TestInterfaceProxy<_AttributeExtensions...>::getTestPredefinedTypeAttributeAttribute() {
    return delegate_->getTestPredefinedTypeAttributeAttribute();
}

template <typename ... _AttributeExtensions>
typename TestInterfaceProxy<_AttributeExtensions...>::TestDerivedStructAttributeAttribute& TestInterfaceProxy<_AttributeExtensions...>::getTestDerivedStructAttributeAttribute() {
    return delegate_->getTestDerivedStructAttributeAttribute();
}

template <typename ... _AttributeExtensions>
typename TestInterfaceProxy<_AttributeExtensions...>::TestDerivedArrayAttributeAttribute& TestInterfaceProxy<_AttributeExtensions...>::getTestDerivedArrayAttributeAttribute() {
    return delegate_->getTestDerivedArrayAttributeAttribute();
}


template <typename ... _AttributeExtensions>
typename TestInterfaceProxy<_AttributeExtensions...>::TestPredefinedTypeBroadcastEvent& TestInterfaceProxy<_AttributeExtensions...>::getTestPredefinedTypeBroadcastEvent() {
    return delegate_->getTestPredefinedTypeBroadcastEvent();
}


template <typename ... _AttributeExtensions>
void TestInterfaceProxy<_AttributeExtensions...>::testEmptyMethod(CommonAPI::CallStatus& callStatus) {
    delegate_->testEmptyMethod(callStatus);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> TestInterfaceProxy<_AttributeExtensions...>::testEmptyMethodAsync(TestEmptyMethodAsyncCallback callback) {
    return delegate_->testEmptyMethodAsync(callback);
}

template <typename ... _AttributeExtensions>
void TestInterfaceProxy<_AttributeExtensions...>::testVoidPredefinedTypeMethod(const uint32_t& uint32Value, const std::string& stringValue, CommonAPI::CallStatus& callStatus) {
    delegate_->testVoidPredefinedTypeMethod(uint32Value, stringValue, callStatus);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> TestInterfaceProxy<_AttributeExtensions...>::testVoidPredefinedTypeMethodAsync(const uint32_t& uint32Value, const std::string& stringValue, TestVoidPredefinedTypeMethodAsyncCallback callback) {
    return delegate_->testVoidPredefinedTypeMethodAsync(uint32Value, stringValue, callback);
}

template <typename ... _AttributeExtensions>
void TestInterfaceProxy<_AttributeExtensions...>::testPredefinedTypeMethod(const uint32_t& uint32InValue, const std::string& stringInValue, CommonAPI::CallStatus& callStatus, uint32_t& uint32OutValue, std::string& stringOutValue) {
    delegate_->testPredefinedTypeMethod(uint32InValue, stringInValue, callStatus, uint32OutValue, stringOutValue);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> TestInterfaceProxy<_AttributeExtensions...>::testPredefinedTypeMethodAsync(const uint32_t& uint32InValue, const std::string& stringInValue, TestPredefinedTypeMethodAsyncCallback callback) {
    return delegate_->testPredefinedTypeMethodAsync(uint32InValue, stringInValue, callback);
}

template <typename ... _AttributeExtensions>
void TestInterfaceProxy<_AttributeExtensions...>::testVoidDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, CommonAPI::CallStatus& callStatus) {
    delegate_->testVoidDerivedTypeMethod(testEnumExtended2Value, testMapValue, callStatus);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> TestInterfaceProxy<_AttributeExtensions...>::testVoidDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2Value, const DerivedTypeCollection::TestMap& testMapValue, TestVoidDerivedTypeMethodAsyncCallback callback) {
    return delegate_->testVoidDerivedTypeMethodAsync(testEnumExtended2Value, testMapValue, callback);
}

template <typename ... _AttributeExtensions>
void TestInterfaceProxy<_AttributeExtensions...>::testDerivedTypeMethod(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, CommonAPI::CallStatus& callStatus, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue) {
    delegate_->testDerivedTypeMethod(testEnumExtended2InValue, testMapInValue, callStatus, testEnumExtended2OutValue, testMapOutValue);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> TestInterfaceProxy<_AttributeExtensions...>::testDerivedTypeMethodAsync(const DerivedTypeCollection::TestEnumExtended2& testEnumExtended2InValue, const DerivedTypeCollection::TestMap& testMapInValue, TestDerivedTypeMethodAsyncCallback callback) {
    return delegate_->testDerivedTypeMethodAsync(testEnumExtended2InValue, testMapInValue, callback);
}


template <typename ... _AttributeExtensions>
std::string TestInterfaceProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
const std::string& TestInterfaceProxy<_AttributeExtensions...>::getDomain() const {
    return delegate_->getDomain();
}

template <typename ... _AttributeExtensions>
const std::string& TestInterfaceProxy<_AttributeExtensions...>::getServiceId() const {
    return delegate_->getServiceId();
}

template <typename ... _AttributeExtensions>
const std::string& TestInterfaceProxy<_AttributeExtensions...>::getInstanceId() const {
    return delegate_->getInstanceId();
}

template <typename ... _AttributeExtensions>
bool TestInterfaceProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& TestInterfaceProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& TestInterfaceProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}

} // namespace tests
} // namespace commonapi

namespace CommonAPI {
template<template<typename > class _AttributeExtension>
struct DefaultAttributeProxyFactoryHelper<commonapi::tests::TestInterfaceProxy,
    _AttributeExtension> {
    typedef typename commonapi::tests::TestInterfaceProxy<
            commonapi::tests::TestInterfaceExtensions::TestPredefinedTypeAttributeAttributeExtension<_AttributeExtension>, 
            commonapi::tests::TestInterfaceExtensions::TestDerivedStructAttributeAttributeExtension<_AttributeExtension>, 
            commonapi::tests::TestInterfaceExtensions::TestDerivedArrayAttributeAttributeExtension<_AttributeExtension>
    > class_t;
};
}


#endif // COMMONAPI_TESTS_TEST_INTERFACE_PROXY_H_
