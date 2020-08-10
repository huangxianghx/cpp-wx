# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8.12.2)

# 项目信息
project(cpp-wx)

# 设置c++环境
set(CMAKE_CXX_STANDARD 14)

# 指定生成目标
add_executable(grpc_server grpcServer.cc helloworld.pb.cc helloworld.grpc.pb.cc)

# 引入lib链接库
target_link_libraries(grpc_server gRPC::grpc++_reflection gRPC::grpc++ libprotobuf )
