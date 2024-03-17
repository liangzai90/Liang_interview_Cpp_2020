#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>
#include <execution>  // for_each

//C++17 base16编码

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

void testStr() {
    std::vector<unsigned char> in_data;
    in_data.resize(1024 * 1024 * 20-1); // 20M
    for(std::size_t i=0; i<in_data.size(); i++){
        in_data[i] = i%256;
    }
    std::vector<unsigned char> out_data;
    out_data.resize(in_data.size() * 2);

    // 测试C++17 多线程base16 编码
    std::cout<<"C++17 多线程 base16编码，开始计算"<<std::endl;
    auto start = std::chrono::system_clock::now();

    // do some thing.
    unsigned char* idata = in_data.data();
    unsigned char* odata = out_data.data();
    //#include <execution>  c++17
    std::for_each(std::execution::par, 
        in_data.begin(), in_data.end(),
        [&](auto& d){
            char a = base16[d>>4];
            char b = base16[d&0x0F];
            int index = &d - idata;
            odata[index *2] = a;
            odata[index *2+1] = b;
    });

    auto end = std::chrono::system_clock::now();    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"编码："<<in_data.size() <<"字节数据，" 
    <<"耗时:"<<duration.count()<<std::endl;
}

void test_foreach(){
    std::vector<int> vt={1,2,3,4,5,6,7,8,9,10};
    std::for_each(std::execution::par,vt.begin(),vt.end(),[](auto& i){
        std::cout<<i<<" ";
    });
}


/**
 * 安装tbb库， stl并行计算需要用到这个库
 * sudo yum install tbb-devel tbb
 * 
 * 查找tbb头文件路径
 * sudo find / -name "blocked_range.h" 2>/dev/null
 * 
 * **/


// centos7 C++17下面编译这个并行计算有问题，编译不通过。主要还是环境问题。

int main() {
//    testStr() ;
    test_foreach();
    
    return 0;
}

