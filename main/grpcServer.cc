//
// Created by 黄湘 on 2020/7/25.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include <exception>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "apis/hello.grpc.pb.h"


using namespace std;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using protocol::hello::v1::HelloReq;
using protocol::hello::v1::HelloResp;
using protocol::hello::v1::HelloAPI;

int socket_fd;


// Logic and data behind the server's behavior.
class HelloServiceImpl final : public HelloAPI::Service {
    Status sayHello(ServerContext* context, const HelloReq* request,
                    HelloResp* reply) override {
        std::string prefix("Hello ");
        reply->set_message(prefix + request->name());
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("47.107.147.126:50051");
    HelloServiceImpl service;
    cout << "1.define server_address、service" << endl;

    grpc::EnableDefaultHealthCheckService(true);
    cout << "2. health check" << endl;

    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    cout << "3. init server builder" << endl;

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    cout << "4. listening port" << endl;

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    cout << "5. register service" << endl;

    try{
        // Finally assemble the server.
        std::unique_ptr<Server> server(builder.BuildAndStart());
        cout << "6. define unique_ptr" << endl;
        std::cout << "Server listening on " << server_address << std::endl;
        // Wait for the server to shutdown. Note that some other thread must be
        // responsible for shutting down the server for this call to ever return.
        server->Wait();
        cout << "7. waiting connecting" << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

}

int main() {
    try{
        cout<< "run grpc server begin" << endl;
        // 启动grpc服务端
        RunServer();
        cout<< "run grpc server end" << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }
}


