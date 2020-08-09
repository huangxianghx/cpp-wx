load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

# 引入依赖包
cc_library(
    name = "user_service",
    srcs = ["user_service.cc","user_dao.cc","mysql_connect.cc"],
    hdrs = ["user_service.h","user_dao.h","mysql_connect.h"],
)

# 定义server执行程序
cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [
        "//lib:user_service",
    ],
)

# 定义client执行程序
cc_binary(
    name = "client",
    srcs = ["client.cc"],
)

# 定义grpcServer执行程序
cc_binary(
    name = "grpcServer",
    srcs = ["grpcServer.cc"],
    deps = [
        "@usr//:grpc_build",
    ],
)

# 定义grpcClient执行程序
cc_binary(
    name = "grpcClient",
    srcs = ["grpcClient.cc"],
    deps = [
            "//apis:hello_service",
            "@usr//:grpc_build",
    ],
)