/*
 * Copyright 2018 The Cartographer Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CARTOGRAPHER_GRPC_HANDLERS_LOAD_STATE_HANDLER_H
#define CARTOGRAPHER_GRPC_HANDLERS_LOAD_STATE_HANDLER_H

#include "cartographer/io/in_memory_proto_stream.h"
#include "cartographer_grpc/framework/rpc_handler.h"
#include "cartographer_grpc/proto/map_builder_service.pb.h"
#include "google/protobuf/empty.pb.h"

namespace cartographer_grpc {
namespace handlers {

class LoadStateHandler
    : public framework::RpcHandler<framework::Stream<proto::LoadStateRequest>,
                                   google::protobuf::Empty> {
 public:
  std::string method_name() const override {
    return "/cartographer_grpc.proto.MapBuilderService/LoadState";
  }
  void OnRequest(const proto::LoadStateRequest& request) override;
  void OnReadsDone() override;

 private:
  cartographer::io::InMemoryProtoStreamReader reader_;
};

}  // namespace handlers
}  // namespace cartographer_grpc

#endif  // CARTOGRAPHER_GRPC_HANDLERS_LOAD_STATE_HANDLER_H
