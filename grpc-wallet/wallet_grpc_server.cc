//
// Created by 黄湘 on 2020/7/25.
//
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "grpc-wallet/wallet.grpc.pb.h"
#include "lib/user_balance_service.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using wallet::WalletService;
using wallet::ChargeRequest;
using wallet::ChargeResponse;
using wallet::ConsumeRequest;
using wallet::ConsumeResponse;
using wallet::QueryBalanceRequest;
using wallet::QueryBalanceResponse;
using wallet::QueryOrderRequest;
using wallet::QueryOrderResponse;

UserBalanceService userBalanceService;

/**
 * 声明grpc stub
 */
class WalletServiceImpl final : public WalletService::Service {

    Status Charge(ServerContext* context, const ChargeRequest* request,
                  ChargeResponse* response) override {
        // todo...
        userBalanceService.charge(request->userid(),request->orderid(),request->amount());
        response->set_orderid(request->orderid());
        return Status::OK;
    }

    Status Consume(ServerContext* context, const ConsumeRequest* request,
                   ConsumeResponse* response) override {
        // todo...
        userBalanceService.consume(request->userid(),request->orderid(),request->amount());
        return Status::OK;
    }

    Status QueryBalance(ServerContext* context, const QueryBalanceRequest* request,
                      QueryBalanceResponse* response) override {
        // todo...
        userBalanceService.queryBalance(request->userid());
        return Status::OK;
    }

    Status QueryOrder(ServerContext* context, const QueryOrderRequest* request,
                      QueryOrderResponse* response) override {
        // todo...
        userBalanceService.queryOrder(request->userid(),request->orderid());
        return Status::OK;
    }
};


/**
 * 启动grpc服务端
 */
void RunServer() {
    std::string server_address("127.0.0.1:50051");
    // 定义服务
    WalletServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}



