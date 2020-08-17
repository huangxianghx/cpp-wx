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
#include "grpc-wallet/wallet.grpc.pb.h"


using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using wallet::WalletService;


int socket_fd;

/**
 * grpc调用封装
 */
class WalletServiceClient {
public:
    WalletServiceClient(std::shared_ptr<Channel> channel)
            : stub_(WalletService::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string Charge(const std::string& userId,const std::string& orderId,const double& amount) {
        // Data we are sending to the server.
        wallet::ChargeRequest request;
        request.set_userid(userId);
        request.set_orderid(orderId);
        request.set_amount(amount);

        // Container for the data we expect from the server.
        wallet::ChargeResponse response;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->Charge(&context, request, &response);

        // Act upon its status.
        if (status.ok()) {
            cout << response.orderid();
            return "RPC success";
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<WalletService::Stub> stub_;
};


int main() {
    // grpc调用
    string target_str = "127.0.0.1:50051";
    WalletServiceClient walletServiceClient(grpc::CreateChannel(
            target_str, grpc::InsecureChannelCredentials()));
    std::string reply = walletServiceClient.Charge("userId","orderId",100);
    std::cout << "Hello received: " << reply << std::endl;
}
