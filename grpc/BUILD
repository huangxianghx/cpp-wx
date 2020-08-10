load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@bazel_tools//tools/build_defs/cc_grpc_library.bzl", "cc_grpc_library")

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

cc_binary(
    name = "grpcServer",
    srcs = ["grpcServer.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":helloworld_cc_grpc",
        "//:grpc++",
        "//:grpc++_reflection",
    ],
)