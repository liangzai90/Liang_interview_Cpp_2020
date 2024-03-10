#include <iostream>
#include <thread>
#include <string>
#include <mutex>

// unique_lock 常用的3种方式


int main(int argc, char* argv[]) {

    {
        static std::mutex mux;
        {
            std::unique_lock<std::mutex> lock(mux); //出栈区会自动释放
            lock.unlock();
            //临时释放锁 后，还可以再加锁回来
            lock.lock();
        }


        {
            //已经拥有锁，不锁定，退出栈区解锁
            mux.lock();
            std::unique_lock<std::mutex> lock(mux, std::adopt_lock);
        }

        {
            //延后加锁，不拥有，退出栈区 不解锁（因此如果要释放，则必须手动调用一次lock()）
            std::unique_lock<std::mutex> lock(mux, std::defer_lock);
            //加锁，退出栈区解锁
            lock.lock();
        }

        {
            //mux.lock();
            //尝试加锁，不阻塞，失败不拥有锁   
            std::unique_lock<std::mutex> lock(mux, std::try_to_lock);
            if(lock.owns_lock()){
                std::cout<<" owns lock "<<std::endl;
            } else {
                std::cout<<" not owns lock "<<std::endl;
            }
        }
    }

    getchar();
    return 0;
}
