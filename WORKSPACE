#定义外部库空间
new_local_repository(
    name = "usr",
    path = "/usr",
    build_file = "usr.BUILD"
)

# grpc Release v1.30.2
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/de6defa6fff08de20e36f9168f5b277e292daf46.tar.gz",
    ],
    strip_prefix = "grpc-de6defa6fff08de20e36f9168f5b277e292daf46",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()