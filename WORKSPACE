#定义外部库空间
new_local_repository(
    name = "usr",
    path = "/usr",
    build_file = "usr.BUILD"
)

# grpc tag 1.27.3
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/e73882dc0fcedab1ffe789e44ed6254819639ce3.tar.gz",
    ],
    strip_prefix = "grpc-e73882dc0fcedab1ffe789e44ed6254819639ce3",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()
