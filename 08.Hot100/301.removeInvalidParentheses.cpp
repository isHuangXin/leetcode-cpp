//
// Created by huangxin on 2023/9/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

//class Solution {
//public:
//    void generatePermutations(vector<string>& permutations, string& str, int left, int right) {
//        if (left == right) {
//            permutations.push_back(str);
//            return;
//        }
//
//        for (int i = left; i <= right; i++) {
//            swap(str[left], str[i]);
//            generatePermutations(permutations, str, left + 1, right);
//            swap(str[left], str[i]); // 恢复原始状态，以便继续生成其他排列
//        }
//    }
//
//    bool isValidBacket(string one_permutation_s) {
//        unordered_map<char, char> unorderedMap;
////        unorderedMap['('] = ')';
//        unorderedMap[')'] = '(';
//        stack<char> s_stack;
//        s_stack.push(one_permutation_s[0]);
//        for (int i = 1; i < one_permutation_s.size(); i++) {
//            bool isEnglish = (one_permutation_s[i] > 'a' && one_permutation_s[i] < 'z') || (one_permutation_s[i] > 'A' && one_permutation_s[i] < 'Z');
//            if(!s_stack.empty()) {
//                if (unorderedMap[one_permutation_s[i]] == s_stack.top()) {
//                    s_stack.pop();
//                    continue;
//                }
//            }
//            if (!isEnglish) {
//                s_stack.push(one_permutation_s[i]);
//            }
//        }
//        if(s_stack.size()==0) {
//            return true;
//        }
//        return false;
//    }
//
//    vector<string> removeInvalidParentheses(string s) {
//        unordered_map<char, char> unorderedMap;
////        unorderedMap['('] = ')';
//        unorderedMap[')'] = '(';
//
//        stack<char> s_stack;
//        stack<int> num_stack;
//        s_stack.push(s[0]);
//        num_stack.push(0);
//        for (int i = 1; i < s.size(); i++) {
//            if (!s_stack.empty()) {
//                if(unorderedMap[s[i]] == s_stack.top()) {
//                    s_stack.pop();
//                    num_stack.pop();
//                }
//            } else {
//                s_stack.push(s[i]);
//                num_stack.push(i);
//            }
//        }
//        string one_valid_string = "";
//        for (int i = 0; i < s.size(); i++) {
//            for (int j = 0; j < num_stack.size(); ++j) {
//                if(i != num_stack.top()) {
//                    one_valid_string += s[i];
//                }
//            }
//        }
//
//        vector<string> all_permutation;
////        do {
////            all_permutation.push_back(one_valid_string);
////        } while (next_permutation(one_valid_string.begin(), one_valid_string.end()));
//        generatePermutations(all_permutation, one_valid_string, 0, one_valid_string.size() - 1);
//
//        vector<string> res;
//        for (int i = 0; i < all_permutation.size(); i++) {
//            bool flag = isValidBacket(all_permutation[i]);
//            if (flag) {
//                res.push_back(all_permutation[i]);
//            }
//        }
//        return res;
//    }
//};

int main() {
    string s = "()())()";
    Solution solution;
    vector<string> res = solution.removeInvalidParentheses(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}