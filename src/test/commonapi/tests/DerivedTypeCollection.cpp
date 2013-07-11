/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "DerivedTypeCollection.h"

namespace commonapi {
namespace tests {
namespace DerivedTypeCollection {

TestStructExtended::TestStructExtended(const PredefinedTypeCollection::TestString& testStringValue, const uint16_t& uintValueValue, const TestEnumExtended2& testEnumExtended2Value):
        TestStruct(testStringValue, uintValueValue),
        testEnumExtended2(testEnumExtended2Value)
{
}

bool operator==(const TestStructExtended& lhs, const TestStructExtended& rhs) {
    if (&lhs == &rhs)
        return true;

    return
        static_cast<TestStructExtended::TestStruct>(lhs) == static_cast<TestStructExtended::TestStruct>(rhs) &&
        lhs.testEnumExtended2 == rhs.testEnumExtended2
    ;
}

void TestStructExtended::readFromInputStream(CommonAPI::InputStream& inputStream) {
    TestStruct::readFromInputStream(inputStream);
    inputStream >> testEnumExtended2;
}

void TestStructExtended::writeToOutputStream(CommonAPI::OutputStream& outputStream) const {
    TestStruct::writeToOutputStream(outputStream);
    outputStream << testEnumExtended2;
}
TestStruct::TestStruct(const PredefinedTypeCollection::TestString& testStringValue, const uint16_t& uintValueValue):
        testString(testStringValue),
        uintValue(uintValueValue)
{
}

bool operator==(const TestStruct& lhs, const TestStruct& rhs) {
    if (&lhs == &rhs)
        return true;

    return
        lhs.testString == rhs.testString &&
        lhs.uintValue == rhs.uintValue
    ;
}

void TestStruct::readFromInputStream(CommonAPI::InputStream& inputStream) {
    inputStream >> testString;
    inputStream >> uintValue;
}

void TestStruct::writeToOutputStream(CommonAPI::OutputStream& outputStream) const {
    outputStream << testString;
    outputStream << uintValue;
}

} // namespace DerivedTypeCollection
} // namespace tests
} // namespace commonapi
