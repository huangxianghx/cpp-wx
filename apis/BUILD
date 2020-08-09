load("@rules_cc//cc:defs.bzl", "cc_library")

# 定义库
cc_library(
    name = "hello_service",
    srcs = ["helloworld.pb.cc","helloworld.grpc.pb.cc"],
    hdrs = ["helloworld.pb.h","helloworld.grpc.pb.h"],
    deps = [
            '@com_google_protobuf//:protobuf',
            '@com_github_grpc_grpc//:grpc++',
        ],
        visibility = ["//visibility:public"],
)
