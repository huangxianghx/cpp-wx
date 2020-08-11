load("@io_bazel_rules_go//cpp:def.bzl", "cpp_binary")
load("@org_pubref_rules_protobuf//cpp:rules.bzl", "GRPC_COMPILE_DEPS")

cpp_binary(
    name = "grpc_server",
    srcs = [
        "grpcServer.cc",
    ],
    deps = [
        "//proto:cpp_default_library",
    ] + GRPC_COMPILE_DEPS,
)