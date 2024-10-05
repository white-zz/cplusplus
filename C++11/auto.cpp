#include <iostream>
#include <vector>


// 早在C++98标准中就存在了auto关键字，那时候的作用是让变量变成自动变量，拥有自动的生命周期，但是临时变量在声明的时候本身就是自动生命周期了，所以这显得很多余

int main()
{

// auto 的基本使用  
// auto 只是一个占位符，在编译的过程中是会被真正的类型替换掉


/*
  1.复杂类型的推导
    在容器迭代器中，简化声明
    迭代器提供一种统一的方式来遍历数据集合中的元素. 可以理解成一个指针，指向容器中的元素，要使用的时候需要解引用
*/

    std::vector<int> vecHeight = {1, 2, 3};
    

    printf("遍历方式一\n");
    // 单纯的使用迭代器
    std::vector<int>::iterator it1;
    for (it1 = vecHeight.begin(); it1 != vecHeight.end(); it1++)
    {
        printf(" vec:%d", *it1);
    }
    printf("\n");




    printf("遍历方式二\n");
    // 使用auto简化迭代器的声明

    for (auto it2 = vecHeight.begin(); it2 != vecHeight.end(); it2++)
    {
        // auto 推导出迭代器
        printf(" vec:%d", *it2);
    }
    printf("\n");
    


    printf("遍历方式三\n");
    // 使用增强型for循环，极大简化了遍历的写法
    for (auto item : vecHeight)
    {
        // item 推导出是里面的元素，这个修改这个item 无法修改里面的vector的值，因为是拷贝出来的。 如果要修改可以加一个 &  for (auto &item : vecHeight)
        printf(" vec:%d", item);
        item = 1;
    }
    printf("\n");

}

