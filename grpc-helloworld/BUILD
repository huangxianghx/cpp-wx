load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

# 定义proto文件
grpc_proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
)

# 定义grpc_server执行程序
cc_binary(
    name = "grpc_server",
    srcs = ["grpc_server.cc"],
    deps = [
        ":helloworld_proto",
        '@com_github_grpc_grpc//:grpc++',
        '@com_github_grpc_grpc//:grpc++_reflection',
    ],
)
