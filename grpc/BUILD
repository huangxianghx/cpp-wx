load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")



# 定义proto文件
grpc_proto_library(
    name = "helloworld_proto",
    srcs = ["grpc/helloworld.proto"],
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

# 定义grpcServer执行程序
cc_binary(
    name = "grpc_server",
    srcs = ["grpc_server.cc"],
    deps = [
        ":helloworld_cc_proto",
        '@com_google_protobuf//:protobuf',
        '@com_github_grpc_grpc//:grpc++',
        '@com_github_grpc_grpc//:grpc++_reflection',
    ],
)