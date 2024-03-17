#include "xvideo_task.h"
#include <sstream>
#include <iostream>

std::string XVideoTask::windows(){
    // ========== windows 转码格式 ==========
    // ffmpeg -y -i test.mp4 -s 400 x 300 400.mp4 > log.txt 2>&1
    std::stringstream ss;
    ss<<"ffmpeg.exe -y -i "<<in_path<<" ";
    if(width > 0 && height > 0){
        ss <<" -s "<< width<<"x"<<height<<" ";
    }
    ss<<out_path;
    ss<<" > " << std::this_thread::get_id()<<".txt 2>&1";
    return ss.str();
}

    // vtask1->in_path = "test.mp4";
    // vtask1->out_path = "600.mp4";
    // vtask1->width = 640;
    // vtask1->height = 480;
std::string XVideoTask::centos(){
    // ========== centos7 转码格式 ==========
    // ffmpeg -y -i test.mp4 -vf "scale=400:300" 400.mp4
    std::stringstream ss;
    ss<<" ffmpeg -y -i "<<in_path<<" -vf ";
    if(width > 0 && height > 0){
        ss <<" \"scale="<< width<<":"<<height<<"\"  ";  //! 注意这里的空格，格式不对，会导致转码失败
    }
    ss<<out_path;
    auto tid = std::this_thread::get_id();
    ss<<" > task_" << tid <<".txt  2>&1";
    return ss.str();
}

std::string test(){
    std::stringstream ss;
    ss<<" ffmpeg -y -i test.mp4 -vf \"scale=400:300\" 400.mp4  > case4.log 2>&1";
    return ss.str();
}
int XVideoTask::Run(){
    std::string cmd = centos();
    
    std::cout<<"cmd:"<<cmd.c_str()<<std::endl;

    return system(cmd.c_str());
}
