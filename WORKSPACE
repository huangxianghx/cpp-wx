load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

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
        "https://github.com/grpc/grpc/archive/56ad644c329d90c0742a02462b2bd365ff759158.tar.gz",
    ],
    strip_prefix = "grpc-56ad644c329d90c0742a02462b2bd365ff759158",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()
