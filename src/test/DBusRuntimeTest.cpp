/* Copyright (C) 2013 BMW Group
 * Author: Manfred Bathelt (manfred.bathelt@bmw.de)
 * Author: Juergen Gehring (juergen.gehring@bmw.de)
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <gtest/gtest.h>

#include <cstring>

#include <CommonAPI/DBus/DBusRuntime.h>
#include <CommonAPI/DBus/DBusFactory.h>
#include <CommonAPI/DBus/DBusServicePublisher.h>

class DBusRuntimeTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};


TEST_F(DBusRuntimeTest, LoadsDefaultStaticallyLinkedDBusLibrary) {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::load();
    ASSERT_TRUE((bool)runtime);
    CommonAPI::DBus::DBusRuntime* dbusRuntime = dynamic_cast<CommonAPI::DBus::DBusRuntime*>(&(*runtime));
    ASSERT_TRUE(dbusRuntime != NULL);
}


TEST_F(DBusRuntimeTest, LoadsSpecifiedStaticallyLinkedDBusLibrary) {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::load("DBus");
    ASSERT_TRUE((bool)runtime);
    CommonAPI::DBus::DBusRuntime* dbusRuntime = dynamic_cast<CommonAPI::DBus::DBusRuntime*>(&(*runtime));
    ASSERT_TRUE(dbusRuntime != NULL);
}


TEST_F(DBusRuntimeTest, LoadsDBusLibraryAsSingleton) {
#ifdef WIN32
    /*
     access the middlewareInfo in order to get a call to DBusRuntime. This forces the windows linker not to remove DBusRuntime from resulting binary
     */
    ASSERT_TRUE(CommonAPI::DBus::DBusRuntime::middlewareInfo_.middlewareName_);
#endif
    std::shared_ptr<CommonAPI::Runtime> runtime1 = CommonAPI::Runtime::load("DBus");
    std::shared_ptr<CommonAPI::Runtime> runtime2 = CommonAPI::Runtime::load("DBus");
    ASSERT_TRUE((bool)runtime1);
    ASSERT_TRUE((bool)runtime2);

    CommonAPI::DBus::DBusRuntime* dbusRuntime1 = dynamic_cast<CommonAPI::DBus::DBusRuntime*>(&(*runtime1));
    CommonAPI::DBus::DBusRuntime* dbusRuntime2 = dynamic_cast<CommonAPI::DBus::DBusRuntime*>(&(*runtime2));
    ASSERT_TRUE(dbusRuntime1 != NULL);
    ASSERT_TRUE(dbusRuntime2 != NULL);

    ASSERT_TRUE(dbusRuntime1 == dbusRuntime2);
}


TEST_F(DBusRuntimeTest, ReturnsEmptyPointerOnRequestForUnknownMiddleware) {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::load("UnknownMiddlewareId");
    ASSERT_FALSE((bool)runtime);
}


TEST_F(DBusRuntimeTest, DBusRuntimeLoadsDBusFactory) {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::load("DBus");
    ASSERT_TRUE((bool)runtime);
    CommonAPI::DBus::DBusRuntime* dbusRuntime = dynamic_cast<CommonAPI::DBus::DBusRuntime*>(&(*runtime));
    ASSERT_TRUE(dbusRuntime != NULL);

    std::shared_ptr<CommonAPI::Factory> proxyFactory = runtime->createFactory();
    ASSERT_TRUE((bool)proxyFactory);
    CommonAPI::DBus::DBusFactory* dbusProxyFactory = dynamic_cast<CommonAPI::DBus::DBusFactory*>(&(*proxyFactory));
    ASSERT_TRUE(dbusProxyFactory != NULL);
}


TEST_F(DBusRuntimeTest, DBusRuntimeLoadsDBusServicePublisher) {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::load("DBus");
    ASSERT_TRUE((bool)runtime);
    CommonAPI::DBus::DBusRuntime* dbusRuntime = dynamic_cast<CommonAPI::DBus::DBusRuntime*>(&(*runtime));
    ASSERT_TRUE(dbusRuntime != NULL);

    std::shared_ptr<CommonAPI::ServicePublisher> servicePublisher = runtime->getServicePublisher();
    ASSERT_TRUE((bool)servicePublisher);
    CommonAPI::DBus::DBusServicePublisher* dbusServicePublisher = dynamic_cast<CommonAPI::DBus::DBusServicePublisher*>(&(*servicePublisher));
    ASSERT_TRUE(dbusServicePublisher != NULL);
}

#ifndef WIN32
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
