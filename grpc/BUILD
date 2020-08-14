load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

# 定义proto文件
grpc_proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
)

# 定义greet grpc服务
cc_library(
    name = "greet_service",
    srcs = ["greet_service.cc"],
    deps = [":helloworld_proto",]
    visibility = ["//visibility:public"],
)