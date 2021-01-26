//
// Created by Huangxin's macbook air on 1/27/21.
//

#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
    /**
     * 如果作为一个返回值（return value）表示没有找到匹配项
     */
    string filename = "test.txt";
    cout << "filename : " << filename << endl;

    size_t idx = filename.find('.');   //作为return value，表示没有匹配项
    cout<<"string::npos: "<<string::npos<<", "<<"filename.npos: "<<string::npos<<endl;
    cout<<"idx: "<<idx<<", "<<"idx == string::npos: "<<(idx == string::npos)<<endl;
    if(idx == string::npos)
    {
        cout << "filename does not contain any period!" << endl;
    } else{
        // 此时idx != string::npos表示在字符串中找到了子串
        cout << "filename contains the period!" << endl;
    }
}