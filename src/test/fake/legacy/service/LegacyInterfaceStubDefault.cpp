/*
* This file was generated by the CommonAPI Generators. 
* Used org.genivi.commonapi.core 2.1.3.qualifier.
* Used org.franca.core 0.8.10.201309262002.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <fake/legacy/service/LegacyInterfaceStubDefault.h>

namespace fake {
namespace legacy {
namespace service {

LegacyInterfaceStubDefault::LegacyInterfaceStubDefault():
        remoteEventHandler_(this) {
}

LegacyInterfaceStubRemoteEvent* LegacyInterfaceStubDefault::initStubAdapter(const std::shared_ptr<LegacyInterfaceStubAdapter>& stubAdapter) {
    stubAdapter_ = stubAdapter;
    return &remoteEventHandler_;
}


void LegacyInterfaceStubDefault::TestMethod(const std::shared_ptr<CommonAPI::ClientId> clientId, int32_t input, int32_t& val1, int32_t& val2) {
    // Call old style methods in default 
    TestMethod(input, val1, val2);
}
void LegacyInterfaceStubDefault::TestMethod(int32_t input, int32_t& val1, int32_t& val2) {
    // No operation in default
}

void LegacyInterfaceStubDefault::OtherTestMethod(const std::shared_ptr<CommonAPI::ClientId> clientId, std::string& greeting, int32_t& identifier) {
    // Call old style methods in default 
    OtherTestMethod(greeting, identifier);
}
void LegacyInterfaceStubDefault::OtherTestMethod(std::string& greeting, int32_t& identifier) {
    // No operation in default
}

void LegacyInterfaceStubDefault::finish(const std::shared_ptr<CommonAPI::ClientId> clientId) {
    // Call old style methods in default 
    finish();
}
void LegacyInterfaceStubDefault::finish() {
    // No operation in default
}




LegacyInterfaceStubDefault::RemoteEventHandler::RemoteEventHandler(LegacyInterfaceStubDefault* defaultStub):
        defaultStub_(defaultStub) {
}

} // namespace service
} // namespace legacy
} // namespace fake
