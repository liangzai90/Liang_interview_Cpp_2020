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

    auto vtask1 = std::make_shared<XVideoTask>();
    vtask1->in_path = "test.mp4";
    vtask1->out_path = "600.mp4";
    vtask1->width = 640;
    vtask1->height = 480;

    pool.AddTask(vtask1);

    auto fut = vtask1->GetReturn();
    std::cout<<"task ret:"<<fut.get()<<std::endl;
    return 0;
}