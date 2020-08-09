# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8.12.2)

# 项目信息
project(cpp-wx)

# 设置c++环境
set(CMAKE_CXX_STANDARD 14)

# 查找server目录所有源文件，并将名称保存到SERVER_SRC_LIST变量
#aux_source_directory(main SRC_LIST)

# 指定生成目标
add_executable(grpcServer main/grpcServer.cc main/helloworld.grpc.pb.cc main/helloworld.pb.cc)

