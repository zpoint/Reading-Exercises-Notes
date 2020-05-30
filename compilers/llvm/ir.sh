clang -emit-llvm -S func1.c -o func1.ll
clang -emit-llvm -S -O2 func1.c -o func1.ll
# 字节码
llvm-as func1.ll -o func1.bc
clang -emit-llvm -c func1.c -o func1.bc
hexdump -C func1.bc
# 字节码编译成目标平台的汇编代码
llc func1.bc -o func1.s
clang -S func1.bc -o func1.s

# 用汇编器编译成目标文件
as func1.s -o func1.o
# 链接成可执行文件
gcc func1.o -o func1
./func1