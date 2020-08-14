//
// Created by 黄湘 on 2020/8/14.
//

#ifndef CPP_WX_USERSERVICE_H
#define CPP_WX_USERSERVICE_H

using grpc::user::UserService

class UserGrpcService final : public grpc::user::UserService::Service{
public:
    Status SayHello(ServerContext* context, const HelloRequest* request,
                    HelloReply* reply);
};




#endif //CPP_WX_USERSERVICE_H
