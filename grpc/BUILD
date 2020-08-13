load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_java//java:defs.bzl", "java_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

cc_proto_library(
    name = "helloworld_cc_proto",
    deps = [":helloworld_proto"],
)
proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
)

# grpc依赖服务
cc_library(
    name = "hello_grpc",
    srcs = glob(["*.pb.cc"]),
    hdrs = glob(["*.pb.h"]),
    deps = [
            '@com_google_protobuf//:protobuf',
            '@com_github_grpc_grpc//:grpc++',
    ],
)

# 定义grpcServer执行程序
cc_binary(
    name = "grpcServer",
    srcs = ["grpcServer.cc"],
    deps = [
        ":hello_grpc",
    ],
)