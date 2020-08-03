### bazel配置外部库
1、定义外部库空间
```
new_local_repository(
    name = "mysql",
    path = "/usr",
    build_file = "mysql.BUILD"
)
```


2、引入外部库相关文件
```
cc_library(
    name = "mysql_build",
    srcs = glob(["lib64/mysql/*.so"]),
    hdrs = glob(["include/mysql/**"]),
    includes = ["include/mysql"],
    visibility = ["//visibility:public"]

```
)