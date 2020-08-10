load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

cc_binary(
    name = "grpcServer",
    srcs = [
        "grpcServer.cc",
    ],
    copts = [],
    deps = [
        "//:grpc++",
        "//apis:hello_service",
    ],
)