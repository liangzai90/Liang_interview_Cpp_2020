#include <iostream>
#include "xmsg_server.h"

//给当前线程发消息
void XMsgServer::SendMsg(const std::string& msg){
    std::unique_lock<std::mutex> lock(mux_);
    msgs_.push_back(msg);
}

//处理消息的线程入口函数
void XMsgServer::Main(){
    while(!is_exit()){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::unique_lock<std::mutex> lock(mux_);

        if(msgs_.empty()){
            continue;
        }

        while(!msgs_.empty()){
            //消息处理业务逻辑
            std::cout<<" recv : "<<msgs_.front()<<std::endl;
            msgs_.pop_front();
        }
    }
}

