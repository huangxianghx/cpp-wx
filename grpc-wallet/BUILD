load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

# 定义proto文件
grpc_proto_library(
    name = "wallet_proto",
    srcs = ["wallet.proto"],
)

# 定义wallet_grpc_server执行程序
cc_binary(
    name = "wallet_grpc_server",
    srcs = ["wallet_grpc_server.cc"],
    deps = [
        ":wallet_proto",
        "//lib:user_balance_service",
        '@com_github_grpc_grpc//:grpc++',
        '@com_github_grpc_grpc//:grpc++_reflection',
    ],
)
