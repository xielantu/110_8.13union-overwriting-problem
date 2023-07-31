# 110_8.13共用体注意数据覆盖问题


## 结构体和联合体的区别
### 1.结构体元素有各自单独的空间
  联合体元素共享空间，空间大小由最大类型确定
### 2.结构体元素互不影响
   联合体赋值会导致覆盖  

## 示例代码
```cpp
// 110_8.13共用体注意数据覆盖问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
struct TestT
{
    int idata;
    char cdata;
    int ddata;
};

union TestU
{
    int idata;
    char cdata;
    int ddata;
};

int main()
{
    struct TestT t1;
    union TestU u1;
    printf("结构体t1的大小是：%d\n", sizeof(t1));
    printf("联合体u1的大小是：%d\n", sizeof(u1));


    t1.idata = 10;
    t1.cdata = 'c';
    t1.ddata = 20;
    printf("idata:%p,%d\n", &t1.idata,t1.idata);
    printf("ddata:%p,%d\n", &t1.ddata,t1.cdata);
    printf("cdata:%p,%d\n\n\n", &t1.cdata,t1.ddata);


    u1.idata = 10;
    u1.cdata = 'c';
    u1.ddata = 20;
    printf("idata:%p,%d\n", &u1.idata,u1.idata);
    printf("ddata:%p,%d\n", &u1.ddata,u1.cdata);
    printf("cdata:%p,%d\n", &u1.cdata,u1.ddata);

    return 0;
}
```
## 运行结果
![image](https://github.com/xielantu/109_8.12-Reference-to-the-concept-of-union/assets/96539157/8c8d41ac-f4d9-4387-8a8a-11b44a92fec3)

