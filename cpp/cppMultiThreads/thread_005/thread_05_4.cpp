
#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <shared_mutex>
//Linux -lpthread
using namespace std;


// 因为这里需要用到更高版本的C++标准，这里的程序暂时没法通过编译
// 但是更高级的用法，还是需要学习一下

//c++17  共享锁
//shared_mutex smux;

//c++14 
shared_timed_mutex stmux;

void ThreadRead(int i)
{
    for (;;)
    {
        stmux.lock_shared();
        cout << i << " Read" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        stmux.unlock_shared();
        this_thread::sleep_for(chrono::milliseconds(3));
    }
}
void ThreadWrite(int i)
{
    for (;;)
    {
        stmux.lock_shared();
        //读取数据
        stmux.unlock_shared();
        stmux.lock(); //互斥锁 写入
        cout << i << " Write" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        stmux.unlock();
        this_thread::sleep_for(chrono::milliseconds(3));
    }
}
int main(int argc, char* argv[])
{
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadWrite, i + 100);
        th.detach();
    }
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadRead, i + 200);
        th.detach();
    }
    getchar();
    return 0;
}