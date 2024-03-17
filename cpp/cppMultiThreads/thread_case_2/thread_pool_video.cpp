#include <iostream>
#include "xthread_pool.h"
#include "xvideo_task.h"

// 命令行视频转码工具
// ffmpeg 工具
// 用户输入 视频源 输出视频尺寸
// 在线程池中执行 转码任务
// 转码任务调用ffmpeg

// ========== windows 转码格式 ==========
// ffmpeg -y -i test.mp4 -s 400x300 400.mp4 > log.txt 2>&1
 
// ========== centos7 转码格式 ==========
// ffmpeg -i test.mp4 -vf "scale=400:300" 400.mp4
//

int main(){
    XThreadPool pool;
    pool.Init(16);
    pool.Start();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    for(;;){
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout<<std::endl<<"==============================="<<std::endl;

        auto task = std::make_shared<XVideoTask>();
        std::cout<<"请输入命令 （ v  e  l ）";
        std::string cmd;
        std::cin >> cmd;

        if(cmd == "e"){
            break;
        }
        else if(cmd =="l"){
            std::cout<<"task run count = "<< pool.task_run_count()<<std::endl;
            continue;
        }
        std::cout<<"视频源:";
        std::cin>>task->in_path;

        std::cout<<"目标：";
        std::cin>>task->out_path;

        std::cout<<"输出宽度：";
        std::cin>> task->width;

        std::cout<<"输出高：";
        std::cin>> task->height;

        pool.AddTask(task);
    }

    pool.Stop();
    std::cout<<"\n ----finished-----\n";
    return 0;
}