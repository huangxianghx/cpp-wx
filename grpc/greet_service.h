//
// Created by 黄湘 on 2020/8/17.
//

#ifndef CPP_WX_GREET_SERVIC_H
#define CPP_WX_GREET_SERVIC_H

/**
 * 定义类
 */
class GreeterServiceImpl final : public Greeter::Service {
    Status SayHello(ServerContext* context, const HelloRequest* request,
                    HelloReply* reply) override {
        std::string prefix("Hello ");
        reply->set_message(prefix + request->name());
        return Status::OK;
    }
};
#endif //CPP_WX_GREET_SERVIC_H
