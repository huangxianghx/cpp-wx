
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "mysql_build",
    srcs = glob(["lib64/mysql/*.so"]),
    hdrs = glob(["include/mysql/**"]),
    includes = ["include/mysql"],
    visibility = ["//visibility:public"]
)
