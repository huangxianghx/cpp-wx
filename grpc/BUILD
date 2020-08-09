load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

# 定义grpcServer执行程序
cc_binary(
    name = "grpcServer",
    srcs = ["grpcServer.cc","helloworld.pb.cc","helloworld.grpc.pb.cc"],
    deps = [
        "//apis:hello_service",
    ],
)