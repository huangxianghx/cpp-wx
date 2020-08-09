# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.16)

# 项目信息
project(cpp-wx)

# 设置c++环境
set(CMAKE_CXX_STANDARD 14)

# 添加apis子目录
add_subdirectory(apis)

# 查找server目录所有源文件，并将名称保存到SERVER_SRC_LIST变量
#aux_source_directory(main SRC_LIST)

# 指定生成目标
add_executable(grpcServer main/grpcServer.cc main/helloworld.grpc.pb.cc main/helloworld.pb.cc)


# 引入lib链接库
target_link_libraries(grpcServer apis)
