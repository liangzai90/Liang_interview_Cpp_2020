#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <string.h>

static const char base16[] = "0123456789abcdef";


// base16 编码 和 解码
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

//C++11 多核base16编码
void Base16EncodeThread(const unsigned char* data, int size, unsigned char* out){
    int th_count = std::thread::hardware_concurrency(); //获取当前机器的核数

    //切片数据
    int slice_count = size / th_count;//每个线程处理的数据大小
    if(size < slice_count){
        th_count = 1;
        slice_count = size;
    }

    std::cout<<"Base16EncodeThread size:"<<size<<",th_count:"<<th_count<< ",slice_count:"<<slice_count<< std::endl;

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
        ths[i] = std::thread(Base16Encode, data + offset, count, out+offset*2);
    }

    // 等待所有线程处理结果
    for( auto& th : ths){
        th.join();
    }
}


void testStr(const char* original) {
    int original_size = strlen(original);
    unsigned char encoded[original_size * 2 + 1]; // Allocate space for encoded string
    //Base16Encode((const unsigned char*)original, original_size, encoded);
    Base16EncodeThread((const unsigned char*)original, original_size, encoded);
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

    getchar();
    return 0;
}



