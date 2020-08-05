#!/bin/bash

do_build_v1() {
    cwd=`pwd`
    cd ./apis
    cur_dir=`pwd`
    
    src_dir="protocol"
    cpp_dir=${cur_dir}/cpp/${src_dir}
    mkdir -p ${cpp_dir}

    cd ${src_dir}
    protoc \
    -I. \
    --grpc_out="${cpp_dir}" \
    --plugin="protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin" \
    --cpp_out="${cpp_dir}" \
    ./*.proto

    cd ${cwd}
}

do_build_v1

protoc -I="/home/huangxiang/src/main/protoc" --cpp_out="/home/huangxiang/proto" /home/huangxiang/src/main/protoc/hello.proto


protoc -I="/home/huangxiang/src/main/protoc" --grpc_out="/home/huangxiang/proto" --plugin="protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin" --cpp_out = "/home/huangxiang/proto" ./*.proto