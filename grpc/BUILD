load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
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