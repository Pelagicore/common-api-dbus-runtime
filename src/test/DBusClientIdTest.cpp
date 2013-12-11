/* Copyright (C) 2013 BMW Group
 * Author: Manfred Bathelt (manfred.bathelt@bmw.de)
 * Author: Juergen Gehring (juergen.gehring@bmw.de)
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <gtest/gtest.h>
#include "CommonAPI/DBus/DBusClientId.h"
#include "CommonAPI/types.h"

using namespace CommonAPI::DBus;

class DBusClientIdTest: public ::testing::Test {

public:
    void SetUp() {

    }

    void TearDown() {

    }
};

class TestClientId: public CommonAPI::ClientId {
public:
    bool operator==(CommonAPI::ClientId& clientIdToCompare) {
        return false; // doesn't matter, as we are just comparing this class with DBusClientId;
    }

    std::size_t hashCode() {
        return 0;
    }

};

TEST_F(DBusClientIdTest, TestClientIdImplementation) {
    DBusClientId dbusId1("test1");
    DBusClientId dbusId2("test2");
    TestClientId testId;


    ASSERT_TRUE(dbusId1 == dbusId1);
    ASSERT_FALSE(dbusId1 == dbusId2);
    ASSERT_FALSE(dbusId2 == dbusId1);

    ASSERT_FALSE(dbusId1 == testId);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
