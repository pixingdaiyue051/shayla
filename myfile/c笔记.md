### linux c笔记
1. ANSI C
    为避免语法差异指定的国际c语法标准
2. gcc编译c源代码
	- 预编译(Preprocessing 处理头文件)  
		gcc -E a.c -i a.i  
        查找引入头文件 替换宏定义(不考虑语法规则)
	- 编译(Compilation 将源代码编译成汇编)  
		gcc -S a.i -o a.s
	- 汇编(Assembly 汇编文件成目标文件)  
		gcc -c a.s -o a.o
	- 链接(Linking 链接目标文件成可执行文件)  
		gcc a.o -o a
	- 上面4个步骤可以集成一步  
		gcc a.c -o a  
3. 多源文件编译输出到同一个可执行文件  
    - 直接编译源代码  
        gcc 1.c 2.c 3.c -o a.out
    - 代码中使用#include引入其他源文件
    - 先编译其他源代码  
        gcc -c 1.c -o 1.o  
        gcc 1.o 2.c -o a.out
    - 编写.h头文件  
        将函数的声明写成头文件 可以分开编译不同c源文件
    - 编写MakeFile  
    ```MakeFile
    num.out:num.o num_demo.c
        gcc num.o num_demo.c -o num.out
    num.o:num.c
        gcc -c num.c -o num.o
    ```
4. main函数
    ```c
    int main(int argv, char *argc[])
    {
        printf("%d,%s\n", argv, argc);
        for(int i=0;i<argv;i++)
        {
            printf("%s\n", argc[i]);
        }
        return 0;
    }
    ```
    - 返回值0表示程序执行成功  
    返回其他数值可以表示错误错误码 使用echo $?查看代码返回值
    - 参数argv表示一共输入了多少个参数
    - 参数argc表示每个参数的具体内容
5. 标准流
    - 输入流stdin  
    默认将从键盘读取数据到内存
    - 输出流stdout  
    默认将内存数据输出到显示器
    - 错误流stderr  
6. 内存管理
    - 1Byte=8bit (1字节=8位)
    - 所有内存均由os管理
    - os分配每个进程的地址 并对内存进项规划
    - 32位os
        - 指地址总线32位
        - 最大寻址空间32位即2^32=4G
        - 64位os 预留高12位 其他进程使用48位
        - 变量本质是内存
        - 指针本质是内存地址
7.  |地址|说明|作用域|
    |:-:|:-:|:-:|
    |0xffffffffffffffff|64位最大地址|系统内存|
    |0x7fffffffffffffff|48位最大地址|栈|
    |0x7fffffffffffffff|48位最大地址|动态分配|
    |0x7fffffffffffffff|48位最大地址|堆|
    |0x7fffffffffffffff|程序中声明的变量|数据段|
    |0x7fffffffffffffff|源代码编译后的二进制文件|代码块|
### c笔记
1. 数据类型
    - 基本类型
        - 整形
        - 字符
        - 浮点型
    - 构造类型
        - 枚举
        - 数组
        - 结构体
        - 共同体
    - 指针类型
    - 空类型
2. 数据取值范围
    | 数据类型| 字节| 取值范围|
    | :-: | :-: | :-:|
    | char| 1 ||
    |short (int)| 2 | -2^8~2^8-1 |
    |long (int)| 4 | -2^16~2^16-1 |
    |unsigned short (int)| 2 | 0~2^16-1 |
    |unsigned long (int)| 4 | 0~2^32-1 |
    |int|2(32bit) | -2^8~2^8-1 |
    |int|4(64bit) | -2^16~2^16-1 |
    |unsigned int| 2 | 0~2^16-1 |
    |float| 4 |  |
    |double| 8 |  |
    |long double| 16 |  |
    |pointer| 8 |  |
3. 运算符优先级
    | 优先级 | 运算符 |
    | :-: | :-: |
    | 1 | () |
    | 2 | ! ++ -- |
    | 3 | * / % |
    | 4 | + - |
    | 5 | < > <= >= |
    | 6 | == != |
    | 7 | && |
    | 8 | \|\| |
    | 9 | ?: |
    | 10 | = += -= *= /= %= |
4. 变量存储方式
    - 静态存储  
    整个程序执行过程中都存在的变量  
        - 全局变量    
    - 动态存储  
    根据程序运行的需要而建立和释放的
        - 函数形式参数
        - 自动变量
        - 函数调用时的现场保护
        - 函数调用时的返回地址
5. 变量存储类别
    - 自动变量  
    使用auto声明 auto可以省略 属于动态存储方式
    - 静态变量  
    使用static声明 属于静态存储方式
        - 静态局部变量 定义在函数内部
        - 静态外部变量 定义在函数外部
    - 寄存器变量  
    使用register声明 为提高效率将局部变量存储在cpu寄存器内
        - 局部自动变量
        - 函数形参
    - 外部变量  
    使用extern声明  
    ```c
        int x = 100;
        int main()
        {
            // 函数内调用在函数外声明的变量
            extern int x = 10;
        }
    ```
5. 函数分类
    - 外部函数  
    可以被外部源文件引用的函数  
    使用extern声明 extern可以省略  
    系统默认所有函数是外部函数
    - 内部函数  
    只能在当前源文件内引用的函数  
    使用static声明
    - 内联函数  
    使用inline声明的函数
    在编译过程中会在调用处替换省去函数跳转时间
6. 数组  
    - 内存连续
    - 大小固定
    - 数据类型一致
    - 顺序存储
    - c语言没有提供访问数组长度函数
7. 二维数组
    - 初始化可以不指定大小
    - 可以不指定行数 但是需要指定列数
    ```c
    int arr[2][2] = {{1,2},{3,4}};
    int arr[][2] = {1,2,3,4};
    ```
7. 字符串
    ```c
    char str[] = "";
    char str[] = {'f','\0'};
    printf("%s", str);
    puts(str);
    ```
8. 宏定义
    - 使用#define 声明一个宏
    - 函数被频繁调用且函数体短小时可以将函数设计成宏
    - 使用反斜杠\将多行宏定义串联成一行
    - 宏定义只是简单替换没有类型  
    ```c  
    #define MAX(a,b)\
    ({\
        typeof(a) _a = a;\
        typeof(a) _b = b;\
        (void) (&_a == &_b);\
        (_a) > (_b) ? (_a) : (_b);\
    })
    ```
    - typedef 为变量 函数 等其他语言词设置别名
    - 头文件编写规范
    ```c head.h
    #ifndef _HEAD_H
    #define _HEAD_H
    #endif
    ```
### JNI
1. java源代码编译成class  
    javac HelloJNI.java
2. 运行class文件(可以跳过 此时运行也会报错)  
    java HelloJNI
3. 生成头文件  
    javah HelloJNI
4. 根据头文件编写c  
    自动生成的头文件不可删除不可修改 根据头文件内的方法签名提供对应的实现
5. 编译
    ``` shell
    gcc -m64 -Wl,--add-stdcall-alias -I"C:\Program Files\Java\jdk1.8.0_331\include" -I"C:\Program Files\Java\jdk1.8.0_331\include\win32" -shared -o HelloJNI.dll HelloJNI.c
    ```
6. 再次执行第二步  
    如果上面的步骤都没错 到这里所有的文件都已生成 可以正常运行