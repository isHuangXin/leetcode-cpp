#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // 首先去除首尾的空格
        int i = 0;
        while(i < s.size() && s[i] == ' ') {
            i++;
        }
        s = s.substr(i);
        while(s.back() == ' ') {
            s.pop_back();
        }

        // 要开始匹配 . * e/E了
        bool numFlag = false;
        bool dotFlag = false;
        bool eFlag = false;
        for (int i = 0; i < s.size(); i++) {
            // 1. 判定为数字，则添加numFlag为true
            if (s[i] >= '0' && s[i] <= '9') {
                numFlag = true;
            } 
            // 2. 判定为., 需要从未出现过.和从未出现过e
            else if (s[i] == '.' && !dotFlag && !eFlag) {
                dotFlag = true;
            }
            // 3. 判断为e, 需要从未出现过e 而且需要出现过数字
            else if ((s[i] == 'e' || s[i] == 'E') && !eFlag && numFlag) {
                eFlag = true;
                numFlag = false; // 因为e后面还是需要出现数据
            }
            // 判断 + -号只能出现在第一个位置或者e后面
            else if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i-1] == 'e' || s[i-1] == 'E')) {
            }
            // 其他的情况都是非法的
            else { 
                return false;
            }
        }
        return numFlag;
    }
};

int main() {
    string s;
    cin >> s;
    
    Solution solution;
    bool res = solution.isNumber(s);
    cout << res;
    return 0;
}