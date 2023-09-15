// Problem: 151. 反转字符串
// Link: https://leetcode.cn/problems/reverse-words-in-a-string/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') {
            left++;
        }
        while (right >= left && s[right] == ' ') {
            right--;
        }
        deque<string> d;
        string word;
        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                d.push_front(word);
                word = "";
            } else if (c != ' ') {
                word += c;
            }
            left++;
        }
        d.push_front(word);

        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) {
                ans += ' ';
            }
        }
        return ans;
    }
};