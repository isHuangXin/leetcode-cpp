//
// Created by Huangxin's macbook air on 1/27/21.
//

#include <iostream>
using namespace std;

int reverse(int x);

int main(){
    int x = -123;
    int y = 120;
    int z = -120;
    cout<<reverse(x) <<endl;
    cout<< reverse(y) <<endl;
    cout<< reverse(z) <<endl;
    return 0;
}

int reverse(int x) {
    long num=0;
    while(x){
        cout<< x%10<<" ";
        num = num*10+x%10;
        x/=10;
    }
    cout<<" | ";
    if(x<0)
        num *= -1;
    if(num<-2147483648 || num>2147483647)
        num = 0;
    return num;
}