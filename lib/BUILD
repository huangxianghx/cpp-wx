load("@rules_cc//cc:defs.bzl", "cc_library")

# 定义库
cc_library(
    name = "user_balance_service",
    srcs = ["user_balance_service.cc","user_balance_dao.cc","user_balance_model.cc","mysql_connect.cc"],
    hdrs = ["user_balance_service.h","user_balance_dao.h","user_balance_model.h","mysql_connect.h"],
    deps = ["@usr//:mysql_build"],
    visibility = ["//visibility:public"]
)

