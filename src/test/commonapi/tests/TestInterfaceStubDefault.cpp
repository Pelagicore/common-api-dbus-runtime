/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <commonapi/tests/TestInterfaceStubDefault.h>

namespace commonapi {
namespace tests {

TestInterfaceStubDefault::TestInterfaceStubDefault():
        remoteEventHandler_(this) {
}

TestInterfaceStubRemoteEvent* TestInterfaceStubDefault::initStubAdapter(const std::shared_ptr<TestInterfaceStubAdapter>& stubAdapter) {
    stubAdapter_ = stubAdapter;
    return &remoteEventHandler_;
}

const uint32_t& TestInterfaceStubDefault::getTestPredefinedTypeAttributeAttribute() {
    return testPredefinedTypeAttributeAttributeValue_;
}

void TestInterfaceStubDefault::setTestPredefinedTypeAttributeAttribute(uint32_t value) {
    const bool valueChanged = trySetTestPredefinedTypeAttributeAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireTestPredefinedTypeAttributeAttributeChanged(testPredefinedTypeAttributeAttributeValue_);
}

void TestInterfaceStubDefault::onRemoteTestPredefinedTypeAttributeAttributeChanged() {
    // No operation in default
}

bool TestInterfaceStubDefault::trySetTestPredefinedTypeAttributeAttribute(uint32_t value) {
    if (!validateTestPredefinedTypeAttributeAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (testPredefinedTypeAttributeAttributeValue_ != value);
    testPredefinedTypeAttributeAttributeValue_ = std::move(value);
    return valueChanged;
}

bool TestInterfaceStubDefault::validateTestPredefinedTypeAttributeAttributeRequestedValue(const uint32_t& value) {
    return true;
}

bool TestInterfaceStubDefault::RemoteEventHandler::onRemoteSetTestPredefinedTypeAttributeAttribute(uint32_t value) {
    return defaultStub_->trySetTestPredefinedTypeAttributeAttribute(std::move(value));
}

void TestInterfaceStubDefault::RemoteEventHandler::onRemoteTestPredefinedTypeAttributeAttributeChanged() {
    defaultStub_->onRemoteTestPredefinedTypeAttributeAttributeChanged();
}

const DerivedTypeCollection::TestStructExtended& TestInterfaceStubDefault::getTestDerivedStructAttributeAttribute() {
    return testDerivedStructAttributeAttributeValue_;
}

void TestInterfaceStubDefault::setTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended value) {
    const bool valueChanged = trySetTestDerivedStructAttributeAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireTestDerivedStructAttributeAttributeChanged(testDerivedStructAttributeAttributeValue_);
}

void TestInterfaceStubDefault::onRemoteTestDerivedStructAttributeAttributeChanged() {
    // No operation in default
}

bool TestInterfaceStubDefault::trySetTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended value) {
    if (!validateTestDerivedStructAttributeAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (testDerivedStructAttributeAttributeValue_ != value);
    testDerivedStructAttributeAttributeValue_ = std::move(value);
    return valueChanged;
}

bool TestInterfaceStubDefault::validateTestDerivedStructAttributeAttributeRequestedValue(const DerivedTypeCollection::TestStructExtended& value) {
    return true;
}

bool TestInterfaceStubDefault::RemoteEventHandler::onRemoteSetTestDerivedStructAttributeAttribute(DerivedTypeCollection::TestStructExtended value) {
    return defaultStub_->trySetTestDerivedStructAttributeAttribute(std::move(value));
}

void TestInterfaceStubDefault::RemoteEventHandler::onRemoteTestDerivedStructAttributeAttributeChanged() {
    defaultStub_->onRemoteTestDerivedStructAttributeAttributeChanged();
}

const DerivedTypeCollection::TestArrayUInt64& TestInterfaceStubDefault::getTestDerivedArrayAttributeAttribute() {
    return testDerivedArrayAttributeAttributeValue_;
}

void TestInterfaceStubDefault::setTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 value) {
    const bool valueChanged = trySetTestDerivedArrayAttributeAttribute(std::move(value));
    if (valueChanged)
        stubAdapter_->fireTestDerivedArrayAttributeAttributeChanged(testDerivedArrayAttributeAttributeValue_);
}

void TestInterfaceStubDefault::onRemoteTestDerivedArrayAttributeAttributeChanged() {
    // No operation in default
}

bool TestInterfaceStubDefault::trySetTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 value) {
    if (!validateTestDerivedArrayAttributeAttributeRequestedValue(value))
        return false;

    const bool valueChanged = (testDerivedArrayAttributeAttributeValue_ != value);
    testDerivedArrayAttributeAttributeValue_ = std::move(value);
    return valueChanged;
}

bool TestInterfaceStubDefault::validateTestDerivedArrayAttributeAttributeRequestedValue(const DerivedTypeCollection::TestArrayUInt64& value) {
    return true;
}

bool TestInterfaceStubDefault::RemoteEventHandler::onRemoteSetTestDerivedArrayAttributeAttribute(DerivedTypeCollection::TestArrayUInt64 value) {
    return defaultStub_->trySetTestDerivedArrayAttributeAttribute(std::move(value));
}

void TestInterfaceStubDefault::RemoteEventHandler::onRemoteTestDerivedArrayAttributeAttributeChanged() {
    defaultStub_->onRemoteTestDerivedArrayAttributeAttributeChanged();
}


void TestInterfaceStubDefault::testEmptyMethod() {
    // No operation in default
}

void TestInterfaceStubDefault::testVoidPredefinedTypeMethod(uint32_t uint32Value, std::string stringValue) {
    // No operation in default
}

void TestInterfaceStubDefault::testPredefinedTypeMethod(uint32_t uint32InValue, std::string stringInValue, uint32_t& uint32OutValue, std::string& stringOutValue) {
    // No operation in default
}

void TestInterfaceStubDefault::testVoidDerivedTypeMethod(DerivedTypeCollection::TestEnumExtended2 testEnumExtended2Value, DerivedTypeCollection::TestMap testMapValue) {
    // No operation in default
}

void TestInterfaceStubDefault::testDerivedTypeMethod(DerivedTypeCollection::TestEnumExtended2 testEnumExtended2InValue, DerivedTypeCollection::TestMap testMapInValue, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue) {
    // No operation in default
}


void TestInterfaceStubDefault::fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue) {
    stubAdapter_->fireTestPredefinedTypeBroadcastEvent(uint32Value, stringValue);
}

TestInterfaceStubDefault::RemoteEventHandler::RemoteEventHandler(TestInterfaceStubDefault* defaultStub):
        defaultStub_(defaultStub) {
}

} // namespace tests
} // namespace commonapi
