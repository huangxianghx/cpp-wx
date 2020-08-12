load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

load("@rules_proto//proto:defs.bzl", "proto_library")
load("//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("//bazel:grpc_build_system.bzl", "grpc_proto_library")


# The following three rules demonstrate the usage of the cc_grpc_library rule in
# in a mode compatible with the native proto_library and cc_proto_library rules.
proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
)

cc_proto_library(
    name = "helloworld_cc_proto",
    deps = [":helloworld_proto"],
)

cc_grpc_library(
    name = "helloworld_cc_grpc",
    srcs = [":helloworld_proto"],
    grpc_only = True,
    deps = [":helloworld_cc_proto"],
)

# grpc依赖服务
cc_library(
    name = "hello_service",
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
        ":hello_service",
    ],
)