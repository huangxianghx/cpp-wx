//
// Created by 黄湘 on 2020/8/17.
//

#ifndef CPP_WX_GREET_SERVIC_H
#define CPP_WX_GREET_SERVIC_H
#include<iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "grpc/helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;
/**
 * 定义类
 */
class GreeterServiceImpl final : public Greeter::Service {
public:
    Status SayHello(ServerContext* context, const HelloRequest* request,
                    HelloReply* reply);
};
#endif //CPP_WX_GREET_SERVIC_H
