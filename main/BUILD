load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "user_service",
    srcs = ["user_service.cc","user_dao.cc","mysql_connect.cc"],
    hdrs = ["user_service.h","user_dao.h","mysql_connect.h"],
)

cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [
        "//lib:user_service",
    ],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
)