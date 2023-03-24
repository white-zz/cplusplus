#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//C++11 中提供的线程类叫做 std::thread, 我们只需要提供线程函数即可

//公共成员函数 
// get_id()
// join()  线程没执行完，会被阻塞.如果执行万了会回收相关资源，向下执行
// detach()  分离子线程，子线程执行完，子线程自动释放资源。如果主线程先执行完，子线程还没执行完，也会被释放资源
//  joinable() 判断主线程和子线程的关联关系




// 同样地线程被创建后也有这五种状态：创建态，就绪态，运行态，阻塞态(挂起态)，退出态(终止态) 。
// 命名空间 this_thread 中提供了一个休眠函数 sleep_for()，调用这个函数的线程会马上从运行态变成阻塞态并在这种状态下休眠一定的时长，因为阻塞态的线程已经让出了 CPU 资源，代码也不会被执行，所以线程休眠过程中对 CPU 来说没有任何负担
// this_thread::sleep_for(chrono::seconds(1));



void func(int num, string str)
{
    cout << "线程的线程ID: " << this_thread::get_id() << endl;   //得到当前线程id

    for (int i = 0; i < 10; ++i)
    {
        cout << "子线程: i = " << i << "num: " 
             << num << ", str: " << str << endl;
    }
}

void func1()
{
    cout << "线程的线程ID: " << this_thread::get_id() << endl;   //得到当前线程id

    for (int i = 0; i < 10; ++i)
    {
        cout << "子线程: i = " << i << endl;
    }
}

int main()   //主线程
{
    cout << "主线程的线程ID: " << this_thread::get_id() << endl;   //得到当前线程id
    thread t1(func, 520, "i love you");   //创建子线程1
    thread t2(func1);       //创建子线程2
    // cout << "线程t1 的线程ID: " << t1.get_id() << endl;
    // cout << "线程t2的线程ID: " << t2.get_id() << endl;
    t1.join();
    t2.join();
}
