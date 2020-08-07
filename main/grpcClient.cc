//
// Created by 黄湘 on 2020/7/25.
//

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include <grpcpp/grpcpp.h>
#include "apis/hello.grpc.pb.h"


using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using protocol::hello::v1::HelloReq;
using protocol::hello::v1::HelloResp;
using protocol::hello::v1::HelloAPI;

int socket_fd;

/**
 * grpc调用封装
 */
class HelloClient {
public:
    HelloClient(std::shared_ptr<Channel> channel)
            : stub_(HelloAPI::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string sayHello(const std::string& user) {
        // Data we are sending to the server.
        HelloReq request;
        request.set_name(user);

        // Container for the data we expect from the server.
        HelloResp reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->sayHello(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<HelloAPI::Stub> stub_;
};


int main() {
    // grpc调用
    string target_str = "47.107.147.126:50051";
    HelloClient hello(grpc::CreateChannel(
            target_str, grpc::InsecureChannelCredentials()));
    std::string user("world");
    std::string reply = hello.sayHello(user);
    std::cout << "Hello received: " << reply << std::endl;
}
