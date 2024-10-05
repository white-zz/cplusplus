#include <iostream>


void print(const std::string& text)
{
    // text = "chen"; 不能修改
    std::cout << text << std::endl;
}

class MyClass
{
public:
    void doSomething() const 
    {
        // 保证不会修改任何成员变量
        // name = "chen";  这个修改会报错
    }
private:
    std::string name;

};


int main()
{
    // =========  1.定义常变量     ==========
    const int nPersonMax = 100;
    const char szName[] = {"zhang"};

    // 错误的修改
    // nPersonMax = 20;
    // snprintf(szName, sizeof(szName), "chen");


    //===============  2.定义常指针。  有两种 （1）指针指向的值不能变 （2）指针本身的地址不能变  =============

    // （1）指向的值不能变，指向可以以变
    const char *pszName1 = "zhang";
    char const *pszName2 = "zhang";   //像个写法等价

    pszName1 = "chen";
    pszName2 = "chen";



    // （2）指针本身的地址不能变 
    char * const pszName3 = "zhang";
    // pszName2 = "chen";


    //  (3) 指向的值，和本身的地址都不能变
    const char * const pszName4 = "zhang";



    //===============  3.修饰函数参数  =============
    std::string strName("zhang");
    print(strName);
    

    //===============  4.修饰成员函数  =============

    MyClass obj;
    obj.doSomething();

}