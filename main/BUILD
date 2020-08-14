
# 定义grpc_server执行程序
cc_binary(
    name = "grpc_server",
    srcs = ["grpc_server.cc"],
    deps = [
        "//grpc:greet_service",
        '@com_github_grpc_grpc//:grpc++',
        '@com_github_grpc_grpc//:grpc++_reflection',
    ],
)
