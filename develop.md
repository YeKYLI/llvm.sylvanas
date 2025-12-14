cmake --build . -j20
cmake -G Ninja ../llvm \
   -DLLVM_ENABLE_PROJECTS=mlir \
   -DLLVM_TARGETS_TO_BUILD="NVPTX;AArch64" \
   -DCMAKE_BUILD_TYPE=Debug

