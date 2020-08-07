load("@rules_cc//cc:defs.bzl", "cc_library")

# 定义库
cc_library(
    name = "hello_service",
    srcs = ["hello.pb.cc","hello.grpc.pb.cc"],
    hdrs = ["hello.pb.h","hello.grpc.pb.h"],
    visibility = ["//main:__pkg__"],
)

