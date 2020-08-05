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
#include "../apis/hello.pb.h"

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
    std::string SayHello(const std::string& user) {
        // Data we are sending to the server.
        HelloReq request;
        request.set_name(user);

        // Container for the data we expect from the server.
        HelloResp reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->SayHello(&context, request, &reply);

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

int connect() {
    // 创建socket对象
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        cout << "socket 创建失败：" << endl;
        exit(-1);
    }

    // 构造socket连接地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("172.18.4.189");

    // 发起socket连接
    int res = connect(socket_fd, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1) {
        cout << "bind 链接失败" << endl;
        exit(-1);
    }
    cout << "bind 链接成功" << endl;
}

/**
 * 发送消息
 * @param request
 * @return
 */
int write(string request) {
    cout << "发送请求request：" << request << endl;
    write(socket_fd, request.c_str(), sizeof(request));

    char response[255] = {};
    read(socket_fd, response, sizeof(response));
    cout << "请求响应response：" << response << endl;

    return 0;
}

/**
 * 关闭连接
 * @return
 */
int close() {
    close(socket_fd);
    return 0;
}

int main() {
    // grpc调用
    string target_str = "localhost:50051";
    HelloClient hello(grpc::CreateChannel(
            target_str, grpc::InsecureChannelCredentials()));
    std::string user("world");
    std::string reply = hello.SayHello(user);
    std::cout << "Hello received: " << reply << std::endl;

    // 发起socket连接
    connect();
    // 检测命令行输入
    while(true){
        char request[255];
        cin.getline(request,255);
        if (strcmp(request,"exit")==0) {
            write(request);
            break;
        } else {
            write(request);
        }
    }
    close();
    return 0;
}
