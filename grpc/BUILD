load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")


# 定义protoc文件
proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
)

# 生成protoc cpp代码
cc_proto_library(
    name = "helloworld_cc_proto",
    deps = [":helloworld_proto"],
)

# 生成protoc grpc cpp代码
cc_grpc_library(
    name = "helloworld_cc_grpc",
    srcs = [":helloworld_proto"],
    grpc_only = True,
    deps = [":helloworld_cc_proto"],
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
    name = "grpc_server",
    srcs = ["grpc_server.cc"],
    deps = [
        ":hello_grpc",
    ],
)