//
// Created by Huangxin's macbook air on 1/27/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sortString(string s);

int main(){
    string s = "aaaabbbbcccc";
    cout<<sortString(s);
    return 0;
}

string sortString(string s) {
    // step 1: 26个字母桶
    vector<int> charArr(26,0);
    for(char ch:s){
        charArr[ch - 'a']++;
    }
    // step 2: 桶排序
    string res;
    while(res.length() < s.length()){
        // 从左往右筛选
        for(int i=0; i<26; i++){
            if(charArr[i] != 0){
                res.push_back(i+ 'a');
                charArr[i]--;
            }
        }
        // 从右往左筛选
        for(int i=25; i>=0; i--){
            if(charArr[i] != 0){
                res.push_back(i+'a');
                charArr[i]--;
            }
        }
    }
    return res;
}