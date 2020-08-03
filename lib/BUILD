load("@rules_cc//cc:defs.bzl", "cc_library")

# 定义库
cc_library(
    name = "user_service",
    srcs = ["user_service.cc","user_dao.cc","mysql_connect.cc"],
    hdrs = ["user_service.h","user_dao.h","mysql_connect.h"],
    deps = ["@mysql//:mysql_build"],
    visibility = ["//main:__pkg__"],
)

