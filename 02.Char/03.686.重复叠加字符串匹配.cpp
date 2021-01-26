//
// Created by Huangxin's macbook air on 1/26/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int repeatedStringMatch(string a, string b);

int main(){
    string a = "abcd";
    string b = "cdabcdab";
    cout<< repeatedStringMatch(a, b);
    return 0;
}

// KMP algorithm：
int repeatedStringMatch(string a, string b){
    vector<int> next(b.size(), -1);
    // step1：寻找最大相等前后缀
    int i=0, j=-1;
    while(i<b.size()-1){
        cout<<"loop"<<i<<":"<<endl;
        if(j<0 || b[i]==b[j]){
            cout<<"在if语句内, "<<"b["<<i<<"]:"<<b[i]<<", "<<"b["<<j<<"]:"<<b[j]<<endl;
            next[i+1]=j+1;
            i++;
            j++;
        }else{
            cout<<"在else语句内, j: "<<j<<", "<<"next["<<j<<"]:"<<next[j]<<endl;
            j = next[j];
        }
        cout<<"此时i: "<<i<<", "<<"j: "<<j<<endl;
        cout<<"=========="<<endl;
    }
    for(int m=0; m<next.size(); m++){
        cout<< next[m]<<" ";
    }
    i=0,j=0;
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<"重对齐部分:"<<endl;
    while(i-j<a.size()){
        cout<<"i%a.size(): "<<i<<"%"<<a.size()<<"="<<i%a.size()<<endl;
        cout<<"a[i%a.size()]: "<<a[i%a.size()]<<", "<<"b[j]: "<<b[j]<<endl;
        cout<<"============"<<endl;
        if(j<0 || a[i%a.size()]==b[j]){
            i++;
            j++;
            if(j==b.size()){
                break;
            }
        }else{
            j = next[j];
        }
    }
    if(j==b.size())
        return i%a.size()==0?i/a.size():i/a.size()+1;
    else
        return -1;
}

