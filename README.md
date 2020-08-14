### bazel 构建 grpc 服务

1.WORKSPACE引入grpc、protobuf外部库

# 通过http的方式加载grpc库
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/v1.30.2.tar.gz",
    ],
    strip_prefix = "grpc-1.30.2",
)

#加载grpc相关的bazel文件
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()

# 通过github的方式加载protobuf库
git_repository(
    name = "com_google_protobuf",
    remote = "https://github.com/google/protobuf",
    tag = "v3.12.2",
)

2.BUILD文件通过引入grpc_proto_library标签生成proto文件
# 定义proto文件
grpc_proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
)


# 定义grpc_server执行程序
cc_binary(
    name = "grpc_server",
    srcs = ["grpc_server.cc"],
    deps = [
        ":helloworld_proto",
        '@com_github_grpc_grpc//:grpc++',
        '@com_github_grpc_grpc//:grpc++_reflection',
    ],
)

# 定义grpc_client执行程序
cc_binary(
    name = "grpc_client",
    srcs = ["grpc_client.cc"],
    deps = [
        ":helloworld_proto",
        '@com_github_grpc_grpc//:grpc++',
    ],
)
