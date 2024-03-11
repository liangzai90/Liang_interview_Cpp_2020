#include <iostream>
#include <thread>
#include <future>
#include <string>

std::string TestPack(int index){
    std::cout<<"begin Test Pack "<<index<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout<<"end Test Pack ----->>>"<<std::endl;
    return "Test Pack return";
}

int main(int argc, char* argv[]){
    std::packaged_task< std::string(int) > task(TestPack);
    auto result = task.get_future();
    //task(100);

    std::thread th(std::move(task), 200);  //创建线程的时候， TestPack 函数被调用了，但是 TestPack 阻塞了，没有立即返回

    std::cout<<"begin result get "<<std::endl;

    //测试是否超时
    for(int i=0;i<30;i++){
        if(result.wait_for(std::chrono::milliseconds(100)) != std::future_status::ready){
            continue;
        }
    }
    //auto wait_status = result.wait_for(std::chrono::milliseconds(1000));  //std::future_status::ready
    if(result.wait_for(std::chrono::milliseconds(100)) == std::future_status::timeout){
        std::cout<<"wait result timeout "<<std::endl;
    }
    else {
        std::cout<<"result get:"<<result.get()<<std::endl;
    }

    th.join();

    getchar();
    return 0;
}
