load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

# 引入依赖包
cc_library(
    name = "hello_service",
    srcs = ["helloworld.pb.cc","helloworld.grpc.pb.cc"],
    hdrs = ["helloworld.pb.h","helloworld.grpc.pb.h"],
)

# 定义grpcServer执行程序
cc_binary(
    name = "grpcServer",
    srcs = ["grpcServer.cc"],
    deps = [
        "//:grpc++",
        "//apis:hello_service",
    ],
)