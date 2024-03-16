#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

// base16 编码 和 解码
const std::string base16 = "0123456789ABCDEF";

void Base16Encode(const unsigned char* data, int size, unsigned char* out){
    for(int i=0; i<size; i++){
        unsigned char d = data[i];

        // 1234 5678 >>4    0000 1234
        // 1234 5678 &0x0F  0000 5678
        char a = base16[d>>4];
        char b = base16[d&0x0F];
        out[i*2] = a;
        out[i*2+1] = b;
    }
}


//C++11 多核base16编码
void Base16EncodeThread(const std::vector<unsigned char>& data, std::vector<unsigned char>& out){
    int size = data.size();
    int th_count = std::thread::hardware_concurrency(); //获取当前机器的核数

    //切片数据
    int slice_count = size / th_count;//每个线程处理的数据大小
    if(size < th_count){
        th_count = 1;
        slice_count = size;
    }

    //准备好线程
    std::vector<std::thread> ths;
    ths.resize(th_count);

    //任务分配到各个线程
    for(int i=0; i<th_count; i++){
        // 1234 5678 9abc defg hi
        int offset = i * slice_count;
        int count = slice_count;

        //最后一个线程
        if(th_count > 1 && i == th_count -1){
            count = slice_count + size % th_count;
        }
        ths[i] = std::thread(Base16Encode, data.data() + offset, count, out.data());
    }

    // 等待所有线程处理结果
    for( auto& th : ths){
        th.join();
    }
}


void testStr() {
    std::vector<unsigned char> in_data;
    in_data.resize(1024 * 1024 * 200); // 20M
    for(std::size_t i=0; i<in_data.size(); i++){
        in_data[i] = i%256;
    }
    std::vector<unsigned char> out_data;
    out_data.resize(in_data.size() * 2);


    // 测试C++11 多线程base16 编码
    std::cout<<"C++11 多线程 base16编码，开始计算"<<std::endl;
    auto start = std::chrono::system_clock::now();
    Base16EncodeThread(in_data, out_data);
    auto end = std::chrono::system_clock::now();    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"编码："<<in_data.size() <<"字节数据，" 
    <<"耗时:"<<duration.count()<<std::endl;
}

int main() {
    testStr() ;
    
    return 0;
}

