#include <iostream>
#include <vector>

// 引用作为参数
void swap(int &a, int &b)
{
    int nTmp;
    nTmp = a;
    a = b;
    b = nTmp;
}

std::vector<int> g_vecArr{1, 2, 3};

// 引用作为返回值
std::vector<int> &GetVector()
{
    return g_vecArr;
}

int main()
{   
    // 引用作为参数
    int nNum1 = 1, nNum2 = 2;
    swap(nNum1, nNum2);
    printf("nNum1:%d   nNum1:%d\n", nNum1, nNum2);


    // 引用作为返回值
    auto &it1 = GetVector();
    auto it2 = GetVector();
    auto it3 = GetVector();

    // for (auto item : it)
    // {
    //     printf("item %d ", item);
    // }

    printf(" g_vec %p\n", &g_vecArr);
    printf(" it1 %p\n", &it1);   // it1 是引用， 函数返回的是引用的返回值，所以地址和 g_vecArr 相同
    printf(" it2 %p\n", &it2);  // it2 是新的拷贝
    printf(" it3 %p\n", &it3);  // it3 是新的拷贝

    /*
    g_vec 0x404090
    it1 0x404090
    it2 0x7ffca56c0930
    it3 0x7ffca56c0910
    */
}