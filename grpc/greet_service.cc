//
// Created by 黄湘 on 2020/8/14.
//
#include<iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "grpc/helloworld.grpc.pb.h"
#include "grpc/greet_service.h"

using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

Status SayHello(ServerContext* context, const HelloRequest* request,
                HelloReply* reply){
    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
    return Status::OK;
}
