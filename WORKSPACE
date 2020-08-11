load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
 http_archive(
 name = "com_github_grpc_grpc",
 urls = ["https://github.com/grpc/grpc/archive/v1.30.2.tar.gz"],
 strip_prefix = "grpc-1.30.2",
 )

 load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
 grpc_deps()
 load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
 grpc_extra_deps()

#定义外部库空间
new_local_repository(
    name = "usr",
    path = "/usr",
    build_file = "usr.BUILD"
)