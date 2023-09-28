//
// Created by huangxin on 2023/9/28.
//
#include <iostream>
#include <string>

int main() {
    std::string str = "aaa";

    // 使用两个嵌套循环来生成所有可能的子串
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            std::string subStr = str.substr(i, j - i + 1);
            std::cout << subStr << std::endl;
        }
    }

    return 0;
}
