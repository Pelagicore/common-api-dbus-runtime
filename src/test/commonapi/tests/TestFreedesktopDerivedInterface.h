/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 2.1.5.qualifier.
* Used org.franca.core 0.8.10.201309262002.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef COMMONAPI_TESTS_Test_Freedesktop_Derived_Interface_H_
#define COMMONAPI_TESTS_Test_Freedesktop_Derived_Interface_H_



#include <commonapi/tests/TestFreedesktopInterface.h>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/types.h>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace commonapi {
namespace tests {

class TestFreedesktopDerivedInterface: public TestFreedesktopInterface {
 public:
    virtual ~TestFreedesktopDerivedInterface() { }

    static inline const char* getInterfaceId();
    static inline CommonAPI::Version getInterfaceVersion();
};

const char* TestFreedesktopDerivedInterface::getInterfaceId() {
    static const char* interfaceId = "commonapi.tests.TestFreedesktopDerivedInterface";
    return interfaceId;
}

CommonAPI::Version TestFreedesktopDerivedInterface::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}


} // namespace tests
} // namespace commonapi

namespace CommonAPI {

}


namespace std {
    //hashes for types

    //hashes for error types
}

#endif // COMMONAPI_TESTS_Test_Freedesktop_Derived_Interface_H_
