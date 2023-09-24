//
// Created by huangxin on 2023/9/24.
//

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) {
            return -1;
        }
        unordered_map<char, char> unorderedMap;
        unorderedMap[')'] = '(';

        stack<char> s_stack;
        s_stack.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (!s_stack.empty()) {
                if(unorderedMap[s[i]] == s_stack.top()) {
                    s_stack.pop();
                    continue;
                }
            }
            s_stack.push(s[i]);
        }
        int max_len = s.size() - s_stack.size();
        return max_len;
    }
};

int main() {
    string s = "";
//    cin >> s;
    Solution solution;
    int max_len = solution.longestValidParentheses(s);
    cout << max_len << endl;
    return 0;
}