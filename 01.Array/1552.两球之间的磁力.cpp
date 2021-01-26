//
// Created by Huangxin's macbook air on 1/24/21.
//

#include <iostream>
#include <vector>
using namespace std;

bool check(int mid, vector<int>& position, int m);
int maxDistance(vector<int>& position, int m);

int main(){
    vector<int> position;
    int arr[5] = {1,2,3,4,7}, m = 3;
    for (int i = 0; i < 5; i++) {
        position.push_back(arr[i]);
        cout<< position[i] << " ";
    }
    cout<< endl;
    cout << "ans: "<< maxDistance(position,m);
    return 0;
}

bool check(int mid, vector<int>& position, int m){
    int pre = position[0], cnt = 1;
    for(int i=1; i < position.size(); i++){
        if(position[i] - pre >= mid){
            pre = position[i];
            cnt += 1;
        }
    }
    return cnt >= m;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int left = 1, right = position.back() - position[0], ans = -1;
    while(left <= right){
        int mid = (right + left) / 2;
        if(check(mid, position, m)){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}