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