/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef COMMONAPI_TESTS_DERIVED_TYPE_COLLECTION_H_
#define COMMONAPI_TESTS_DERIVED_TYPE_COLLECTION_H_

#include <CommonAPI/InputStream.h>
#include <CommonAPI/OutputStream.h>
#include <CommonAPI/SerializableStruct.h>
#include <CommonAPI/types.h>
#include <commonapi/tests/PredefinedTypeCollection.h>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace commonapi {
namespace tests {

namespace DerivedTypeCollection {
    struct TestStruct: CommonAPI::SerializableStruct {
        PredefinedTypeCollection::TestString testString;
        uint16_t uintValue;
    
        TestStruct() = default;
        TestStruct(const PredefinedTypeCollection::TestString& testString, const uint16_t& uintValue);
    
        virtual void readFromInputStream(CommonAPI::InputStream& inputStream);
        virtual void writeToOutputStream(CommonAPI::OutputStream& outputStream) const;
    
        static inline void writeToTypeOutputStream(CommonAPI::TypeOutputStream& typeOutputStream) {
            typeOutputStream.writeStringType();
            typeOutputStream.writeUInt16Type();
        }
    };
    
    typedef std::vector<TestStruct> TestArrayTestStruct;
    
    typedef std::unordered_map<uint32_t, TestArrayTestStruct> TestMap;
    
    enum class TestEnum: int32_t {
        E_UNKNOWN = 0,
        E_OK = 1,
        E_OUT_OF_RANGE = 2,
        E_NOT_USED = 3
    };
    
    // XXX Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct TestEnumComparator;
    
    enum class TestEnumExtended: int32_t {
        E_UNKNOWN = TestEnum::E_UNKNOWN,
        E_OK = TestEnum::E_OK,
        E_OUT_OF_RANGE = TestEnum::E_OUT_OF_RANGE,
        E_NOT_USED = TestEnum::E_NOT_USED
        ,
        E_NEW = 4
    };
    
    // XXX Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct TestEnumExtendedComparator;
    
    enum class TestEnumExtended2: int32_t {
        E_UNKNOWN = TestEnum::E_UNKNOWN,
        E_OK = TestEnum::E_OK,
        E_OUT_OF_RANGE = TestEnum::E_OUT_OF_RANGE,
        E_NOT_USED = TestEnum::E_NOT_USED,
        
        E_NEW = TestEnumExtended::E_NEW
        ,
        E_NEW2 = 5
    };
    
    // XXX Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct TestEnumExtended2Comparator;
    
    struct TestStructExtended: TestStruct {
        TestEnumExtended2 testEnumExtended2;
    
        TestStructExtended() = default;
        TestStructExtended(const PredefinedTypeCollection::TestString& testString, const uint16_t& uintValue, const TestEnumExtended2& testEnumExtended2);
    
        virtual void readFromInputStream(CommonAPI::InputStream& inputStream);
        virtual void writeToOutputStream(CommonAPI::OutputStream& outputStream) const;
    
        static inline void writeToTypeOutputStream(CommonAPI::TypeOutputStream& typeOutputStream) {
            TestStruct::writeToTypeOutputStream(typeOutputStream);
            typeOutputStream.writeInt32Type();
        }
    };
    
    typedef std::unordered_map<TestEnum, std::string> TestEnumMap;
    
    enum class TestEnumMissingValue: int32_t {
        E1 = 10,
        E2,
        E3 = 2
    };
    
    // XXX Definition of a comparator still is necessary for GCC 4.4.1, topic is fixed since 4.5.1
    struct TestEnumMissingValueComparator;
    
    typedef std::vector<uint64_t> TestArrayUInt64;
    

bool operator==(const TestStructExtended& lhs, const TestStructExtended& rhs);
inline bool operator!=(const TestStructExtended& lhs, const TestStructExtended& rhs) {
    return !(lhs == rhs);
}
inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, TestEnum& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const TestEnum& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct TestEnumComparator {
    inline bool operator()(const TestEnum& lhs, const TestEnum& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};

inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, TestEnumExtended2& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const TestEnumExtended2& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct TestEnumExtended2Comparator {
    inline bool operator()(const TestEnumExtended2& lhs, const TestEnumExtended2& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};


inline bool operator==(const TestEnumExtended2& lhs, const TestEnum& rhs) {
    return static_cast<int32_t>(lhs) == static_cast<int32_t>(rhs);
}
inline bool operator==(const TestEnum& lhs, const TestEnumExtended2& rhs) {
    return static_cast<int32_t>(lhs) == static_cast<int32_t>(rhs);
}
inline bool operator!=(const TestEnumExtended2& lhs, const TestEnum& rhs) {
    return static_cast<int32_t>(lhs) != static_cast<int32_t>(rhs);
}
inline bool operator!=(const TestEnum& lhs, const TestEnumExtended2& rhs) {
    return static_cast<int32_t>(lhs) != static_cast<int32_t>(rhs);
}

inline bool operator==(const TestEnumExtended2& lhs, const TestEnumExtended& rhs) {
    return static_cast<int32_t>(lhs) == static_cast<int32_t>(rhs);
}
inline bool operator==(const TestEnumExtended& lhs, const TestEnumExtended2& rhs) {
    return static_cast<int32_t>(lhs) == static_cast<int32_t>(rhs);
}
inline bool operator!=(const TestEnumExtended2& lhs, const TestEnumExtended& rhs) {
    return static_cast<int32_t>(lhs) != static_cast<int32_t>(rhs);
}
inline bool operator!=(const TestEnumExtended& lhs, const TestEnumExtended2& rhs) {
    return static_cast<int32_t>(lhs) != static_cast<int32_t>(rhs);
}
inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, TestEnumMissingValue& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const TestEnumMissingValue& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct TestEnumMissingValueComparator {
    inline bool operator()(const TestEnumMissingValue& lhs, const TestEnumMissingValue& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};

inline CommonAPI::InputStream& operator>>(CommonAPI::InputStream& inputStream, TestEnumExtended& enumValue) {
    return inputStream.readEnumValue<int32_t>(enumValue);
}

inline CommonAPI::OutputStream& operator<<(CommonAPI::OutputStream& outputStream, const TestEnumExtended& enumValue) {
    return outputStream.writeEnumValue(static_cast<int32_t>(enumValue));
}

struct TestEnumExtendedComparator {
    inline bool operator()(const TestEnumExtended& lhs, const TestEnumExtended& rhs) const {
        return static_cast<int32_t>(lhs) < static_cast<int32_t>(rhs);
    }
};


inline bool operator==(const TestEnumExtended& lhs, const TestEnum& rhs) {
    return static_cast<int32_t>(lhs) == static_cast<int32_t>(rhs);
}
inline bool operator==(const TestEnum& lhs, const TestEnumExtended& rhs) {
    return static_cast<int32_t>(lhs) == static_cast<int32_t>(rhs);
}
inline bool operator!=(const TestEnumExtended& lhs, const TestEnum& rhs) {
    return static_cast<int32_t>(lhs) != static_cast<int32_t>(rhs);
}
inline bool operator!=(const TestEnum& lhs, const TestEnumExtended& rhs) {
    return static_cast<int32_t>(lhs) != static_cast<int32_t>(rhs);
}
bool operator==(const TestStruct& lhs, const TestStruct& rhs);
inline bool operator!=(const TestStruct& lhs, const TestStruct& rhs) {
    return !(lhs == rhs);
}


static inline const char* getTypeCollectionName() {
    return "commonapi.tests.DerivedTypeCollection";
}


} // namespace DerivedTypeCollection

} // namespace tests
} // namespace commonapi

namespace CommonAPI {
	
	template<>
	struct BasicTypeWriter<commonapi::tests::DerivedTypeCollection::TestEnum> {
	    inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
	        typeStream.writeInt32EnumType();
	    }
	};
	
	template<>
	struct InputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnum> {
	    static void beginReadVector(InputStream& inputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnum>& vectorValue) {
	        inputStream.beginReadInt32EnumVector();
	    }
	};
	
	template <>
	struct OutputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnum> {
	    static void beginWriteVector(OutputStream& outputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnum>& vectorValue) {
	        outputStream.beginWriteInt32EnumVector(vectorValue.size());
	    }
	};
	template<>
	struct BasicTypeWriter<commonapi::tests::DerivedTypeCollection::TestEnumExtended2> {
	    inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
	        typeStream.writeInt32EnumType();
	    }
	};
	
	template<>
	struct InputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnumExtended2> {
	    static void beginReadVector(InputStream& inputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnumExtended2>& vectorValue) {
	        inputStream.beginReadInt32EnumVector();
	    }
	};
	
	template <>
	struct OutputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnumExtended2> {
	    static void beginWriteVector(OutputStream& outputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnumExtended2>& vectorValue) {
	        outputStream.beginWriteInt32EnumVector(vectorValue.size());
	    }
	};
	template<>
	struct BasicTypeWriter<commonapi::tests::DerivedTypeCollection::TestEnumMissingValue> {
	    inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
	        typeStream.writeInt32EnumType();
	    }
	};
	
	template<>
	struct InputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnumMissingValue> {
	    static void beginReadVector(InputStream& inputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnumMissingValue>& vectorValue) {
	        inputStream.beginReadInt32EnumVector();
	    }
	};
	
	template <>
	struct OutputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnumMissingValue> {
	    static void beginWriteVector(OutputStream& outputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnumMissingValue>& vectorValue) {
	        outputStream.beginWriteInt32EnumVector(vectorValue.size());
	    }
	};
	template<>
	struct BasicTypeWriter<commonapi::tests::DerivedTypeCollection::TestEnumExtended> {
	    inline static void writeType (CommonAPI::TypeOutputStream& typeStream) {
	        typeStream.writeInt32EnumType();
	    }
	};
	
	template<>
	struct InputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnumExtended> {
	    static void beginReadVector(InputStream& inputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnumExtended>& vectorValue) {
	        inputStream.beginReadInt32EnumVector();
	    }
	};
	
	template <>
	struct OutputStreamVectorHelper<commonapi::tests::DerivedTypeCollection::TestEnumExtended> {
	    static void beginWriteVector(OutputStream& outputStream, const std::vector<commonapi::tests::DerivedTypeCollection::TestEnumExtended>& vectorValue) {
	        outputStream.beginWriteInt32EnumVector(vectorValue.size());
	    }
	};
	
}


namespace std {
    template<>
    struct hash<commonapi::tests::DerivedTypeCollection::TestEnum> {
        inline size_t operator()(const commonapi::tests::DerivedTypeCollection::TestEnum& testEnum) const {
            return static_cast<int32_t>(testEnum);
        }
    };
    template<>
    struct hash<commonapi::tests::DerivedTypeCollection::TestEnumExtended2> {
        inline size_t operator()(const commonapi::tests::DerivedTypeCollection::TestEnumExtended2& testEnumExtended2) const {
            return static_cast<int32_t>(testEnumExtended2);
        }
    };
    template<>
    struct hash<commonapi::tests::DerivedTypeCollection::TestEnumMissingValue> {
        inline size_t operator()(const commonapi::tests::DerivedTypeCollection::TestEnumMissingValue& testEnumMissingValue) const {
            return static_cast<int32_t>(testEnumMissingValue);
        }
    };
    template<>
    struct hash<commonapi::tests::DerivedTypeCollection::TestEnumExtended> {
        inline size_t operator()(const commonapi::tests::DerivedTypeCollection::TestEnumExtended& testEnumExtended) const {
            return static_cast<int32_t>(testEnumExtended);
        }
    };
}

#endif // COMMONAPI_TESTS_DERIVED_TYPE_COLLECTION_H_
