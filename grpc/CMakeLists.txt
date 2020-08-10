# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8.12.2)

# 项目信息
project(cpp-wx)

# 设置c++环境
set(CMAKE_CXX_STANDARD 14)

set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_REFLECTION grpc++_reflection)
set(_GRPC_GRPCPP gRPC::grpc++)


add_executable(grpc_server "grpcServer.cc"
        "helloworld.pb.cc"
        "helloworld.grpc.pb.cc")
target_link_libraries(grpc_server
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
