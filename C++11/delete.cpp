#include <iostream>

class Singleton {
private:
    static Singleton* s_instance;
    Singleton() {};
    // 私有构造函数

    // 删除拷贝构造函数和拷贝赋值运算符
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance()
    {
        if (s_instance == nullptr)
        {
            s_instance = new Singleton();
        }
        return s_instance;
    }
    
    void Print()
    {
        printf("s_instance addr:%p \n", (this));
        // printf("s_instance cast addr:%p \n", static_cast<void *>(this));
    }
};

// 类外初始化静态成员变量
Singleton *Singleton::s_instance = nullptr;


int main()
{
    // 一般单例调用
    Singleton::getInstance()->Print();

    // 错误用法。创建临时对象，但是构造函数是私有的所以不能调用
    // Singleton test;

    // 错误用法，调用了已删除的拷贝构造函数
    // Singleton test = *Singleton::getInstance();

    // 错误：调用了已删除的拷贝赋值运算符
    // Singleton b;
    // b = *Singleton::getInstance();  



    printf("\n=== 栈地址测试 ===\n");
    int a = 1, b = 2, c = 3;
    printf("addr  a:%p b:%p c:%p \n", &a, &b ,&c);
    // 每个int，地址相差4个字节
    // 打印出来地址为什么是12个字符，48位， 理论上来说应该有64位，说是48位地址就够用了，设计就只有48位
    printf("int 类型大小 sizeof :%d\n", sizeof(a));

    printf("=== 栈地址测试 ===\n");


    /*
    === 栈地址测试 ===
    addr  a:0x7fff103fefa8 b:0x7fff103fefa4 c:0x7fff103fefa0 
    int 类型大小 sizeof :4
    === 栈地址测试 ===

    地址长度12位字符， 6个字节， 48位
    */


    printf("\n=== 堆地址测试 ===\n");

    int *pa = new int[3]{1, 2, 3};
    // 这个new分配了3个int的数组，就是分配了 3*12 的空间 。操作系统会随机从堆中的内存选取足够大的内存空间来，返回该内存的头指针
    int *pb = new int[3];

    printf("addr: pa:%p  pb:%p堆中 实际存int的地址\n", pa, pb);
    printf("指针大小 sizeof :%d\n", sizeof(pa));
    printf(" addr1:%p   value1:%d  , addr2:%p   value2:%d  ,addr3:%p   value3:%d \n", pa, *pa, pa + 1, *(pa + 1),  pa + 2, *(pa +2));
    // printf("addr:%p  栈中 pb变量的地址(这个变量存放栈中的指针) \n", &pb);

    /*
    === 堆地址测试 ===
    addr: pa:0x197c2a0  pb:0x197c2c0堆中 实际存int的地址
    指针大小 sizeof :8
     addr1:       0x197c2a0   value1:1  , addr2:0x197c2a4   value2:2  ,addr3:0x197c2a8   value3:3 
    === 堆地址测试 ===

    地址为什么才这么长，猜测左边是不补0显示的指针
    */  

    delete[] pa;
    pa = nullptr;

    delete[] pb;
    pb = nullptr;

    printf("=== 堆地址测试 ===\n");

}

// 了解类的构造函数

// 类的静态函数的使用