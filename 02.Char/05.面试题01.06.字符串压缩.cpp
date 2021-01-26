//
// Created by Huangxin's macbook air on 1/27/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string compressString(string S);

int main(){
    string s = "aabcccccaaa";
    cout<<compressString(s);
    return 0;
}

string compressString(string S) {
    if(S.length() == 0)
        return S;
    string res="";
    int count=1;
    char ch = S[0];
    for(int i=1; i<S.length()+1; i++){
        if(ch == S[i]){
            count++;
        }else{
            res += ch;
            res += to_string(count);
            ch = S[i];
            count = 1;
        }
    }
    // 最后相同的字母由于只遍历到n-1,所以需要单独处理
//    res += ch;
//    res += to_string(count);
    return res.length()<S.length()? res : S;
}