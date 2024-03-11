#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <string.h>

static const char base16[] = "0123456789abcdef";

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


void base16Decode(const unsigned char* data, int size, unsigned char* out) {
    for (int i = 0; i < size; i += 2) {
        int hi = data[i] <= '9' ? data[i] - '0' : (data[i] & 0xDF) - 'A' + 10;
        int lo = data[i + 1] <= '9' ? data[i + 1] - '0' : (data[i + 1] & 0xDF) - 'A' + 10;
        out[i / 2] = (hi << 4) | lo;
    }
}

void testStr(const char* original) {
    int original_size = strlen(original);
    unsigned char encoded[original_size * 2 + 1]; // Allocate space for encoded string
    Base16Encode((const unsigned char*)original, original_size, encoded);
    encoded[original_size * 2] = '\0'; // Null terminate encoded string
    printf("Encoded string: %s\n", encoded);

    unsigned char decoded[original_size + 1]; // Allocate space for decoded string
    base16Decode(encoded, original_size * 2, decoded);
    decoded[original_size] = '\0'; // Null terminate decoded string
    printf("Decoded string: %s\n", decoded);
}

int main(int argc, char* argv[]) {

    const char* original = "这test这是一个测试字符串。henry20240311串"; // 中文字符串
    testStr(original);

    //单线程 base16 编码效率
    {
        //初始化测试数据
        std::vector<unsigned char> in_data;
        in_data.resize(1024 * 1024 * 20); // 20M
        for(std::size_t i=0; i<in_data.size(); i++){
            in_data[i] = i%256;
        }
        std::vector<unsigned char> out_data;
        out_data.resize(in_data.size() * 2);
        std::cout<<"开始计算"<<std::endl;
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        Base16Encode(in_data.data(), in_data.size(), out_data.data());
        
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout<<"编码："<<in_data.size() <<"字节数据，" <<"耗时:"<<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<std::endl;
        std::cout<<"结束计算"<<std::endl;
    }

    getchar();
    return 0;
}
