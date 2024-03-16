#include <iostream>
#include <string>


//C++11风格 base16 编码 和 解码
const std::string base16 = "0123456789ABCDEF";

void Base16Encode(const std::string& data, std::string& out) {
    for (unsigned char d : data) {
        char a = base16[d >> 4];
        char b = base16[d & 0x0F];
        out.push_back(a);
        out.push_back(b);
    }
}

void base16Decode(const std::string& data, std::string& out) {
    for (size_t i = 0; i < data.size(); i += 2) {
        int hi = data[i] <= '9' ? data[i] - '0' : (data[i] & 0xDF) - 'A' + 10;
        int lo = data[i + 1] <= '9' ? data[i + 1] - '0' : (data[i + 1] & 0xDF) - 'A' + 10;
        out.push_back((hi << 4) | lo);
    }
}

void testStr(const std::string& original) {
    std::string encoded;
    Base16Encode(original, encoded);
    std::cout << "Encoded string: " << encoded << std::endl;

    std::string decoded;
    base16Decode(encoded, decoded);
    std::cout << "Decoded string: " << decoded << std::endl;
}

int main() {
    const std::string original = "这test这是一个测试字符串。henry20240311串"; // 中文字符串
    testStr(original);

    const std::string original2 = "test这是一个测试字符串。henry20240311串";
    testStr(original2);

    const std::string original3 = "这test这是一个测试字符串。henry20240311";
    testStr(original3);


    return 0;
}