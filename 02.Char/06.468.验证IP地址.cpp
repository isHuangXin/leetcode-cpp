//
// Created by Huangxin's macbook air on 1/27/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string validIPAddress(string IP);

int main(){
    string IP = "172.16.254.1";
    cout<<validIPAddress(IP);
    return 0;
}

string validIPAddress(string IP) {
    int pos1 = IP.find('.');
    int pos2 = IP.find(':');
    // 字符串中 "." 和 ":" 不能共存，否则不合法
    if ((pos1 == IP.npos and pos2 != IP.npos) || (pos1 != IP.npos and pos2 == IP.npos)) {
        string pattern = (pos1 != IP.npos) ? "." : ":";
        IP += pattern;
        int pos = IP.find(pattern);
        int cnt = 0;
        while (pos != IP.npos) {
            string temp = IP.substr(0, pos);
            if (pattern == ".") {
                if (cnt >= 4 or temp.length() >= 4 or temp.length() == 0)
                    return "Neither";
                //auto被解释为一个自动存储变量的关键字，也就是申明一块临时的变量内存。
                for (auto &c:temp) {
                    if (!isdigit(c))
                        return "Neither";
                }
                int x = stoi(temp);
                // tips: 用户判断 01.01.01.01数字以0开头的情况
                if (to_string(x) != temp)
                    return "Neither";
                if (x < 0 or x >= 256) {
                    return "Neither";
                }
            } else {
                if (cnt >= 8 or temp.length() >= 5 or temp.length() == 0)
                    return "Neither";
                for (auto &c:temp) {
                    if (!isxdigit(c))
                        return "Neither";
                }
            }
            cnt++;
            IP = IP.substr(pos + 1, IP.size());
            pos = IP.find(pattern);
        }
        if (pattern == ".") {
            return (cnt == 4) ? "IPv4" : "Neither";
        } else {
            return (cnt == 8) ? "IPv6" : "Neither";
        }
    }
    return "Neither";
}
