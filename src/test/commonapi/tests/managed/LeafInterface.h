/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 2.1.5.qualifier.
* Used org.franca.core 0.8.10.201309262002.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef COMMONAPI_TESTS_MANAGED_Leaf_Interface_H_
#define COMMONAPI_TESTS_MANAGED_Leaf_Interface_H_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.h>
#include <CommonAPI/OutputStream.h>
#include <CommonAPI/types.h>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace commonapi {
namespace tests {
namespace managed {

class LeafInterface {
 public:
    virtual ~LeafInterface() { }

    static inline const char* getInterfaceId();
    static inline CommonAPI::Version getInterfaceVersion();
    enum class testLeafMethodError: int32_t {
        OK,
        NOTOK
    };
    
    // Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct testLeafMethodErrorComparator;
};

const char* LeafInterface::getInterfaceId() {
    static const char* interfaceId = "commonapi.tests.managed.LeafInterface";
    return interfaceId;
}

CommonAPI::Version LeafInterface::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}

inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, LeafInterface::testLeafMethodError& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const LeafInterface::testLeafMethodError& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct LeafInterface::testLeafMethodErrorComparator {
    inline bool operator()(const testLeafMethodError& lhs, const testLeafMethodError& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};


} // namespace managed
} // namespace tests
} // namespace commonapi

namespace CommonAPI {

}


namespace std {
    //hashes for types

    //hashes for error types
    //Hash for testLeafMethodError
    template<>
    struct hash<commonapi::tests::managed::LeafInterface::testLeafMethodError> {
        inline size_t operator()(const commonapi::tests::managed::LeafInterface::testLeafMethodError& testLeafMethodError) const {
            return static_cast<int32_t>(testLeafMethodError);
        }
    };
}

#endif // COMMONAPI_TESTS_MANAGED_Leaf_Interface_H_
