load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

# 定义库
cc_library(
    name = "hello_service",
    srcs = glob(["*.pb.cc"]),
    hdrs = glob(["*.pb.h"]),
    deps = [
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