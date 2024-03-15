#!/bin/bash

# 设置安装目录和构建类型
# INSTALL_DIR="usr"
INSTALL_DIR="/usr"
CMAKE_BUILD_TYPE="Release"

# 检查并创建安装目录
if [ ! -d "${INSTALL_DIR}" ]; then
    mkdir -p "${INSTALL_DIR}"
fi

# 删除旧的构建目录，然后创建新的构建目录
rm -rf build
mkdir -p build
pushd build

# 配置CMake项目
cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ..

# 并行编译项目
make -j $(nproc)

# 安装项目
make install

# 返回原始目录
popd