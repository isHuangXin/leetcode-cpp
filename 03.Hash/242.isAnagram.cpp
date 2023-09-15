#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 思路1: 字母比较少，数组映射效率比较高
        // 思路2: 直接哈希
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> hashMapS, hashMapT;
        for(const auto &i : s) {
            ++hashMapS[i];
        }
        for(const auto &j : t) {
            ++hashMapT[j];
        }
        if (hashMapS == hashMapT) {
            return true;
        }
        return false;
    }
};