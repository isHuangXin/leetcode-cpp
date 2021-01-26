//
// Created by Huangxin's macbook air on 1/26/21.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s);

int main(){
    string s;
    cin>>s;
    cout<<calculate(s);
    return 0;
}

int calculate(string s) {
    stack<int> sta;
    char c;
    int num=0;
    for(int i=0;i<=s.length();i++){     //这里是i<=s.length();一定要有等号！！！
        if(isdigit(s[i])){
            num=num*10+(s[i]-'0');
        }else if(isspace(s[i])){
            continue;
        }else{
            //c = s[i];
            switch(c){
                case '+':sta.push(num);break;
                case '-':sta.push(-num);break;
                case '*':num*=sta.top();sta.pop();sta.push(num);break;
                case '/':num=sta.top()/num;sta.pop();sta.push(num);break;
            }
            num=0;
            c=s[i];
        }
    }
    int res=0;
    while(!sta.empty()){
        res+=sta.top();
        sta.pop();
    }
    return res;
}

