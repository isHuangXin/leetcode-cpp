//
// Created by huangxin on 5/13/22.
//

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int minValue = *min_element(numbers.begin(), numbers.end());
        int minPosition = min_element(numbers.begin(), numbers.end()) - numbers.begin();
        while (minPosition > 0){
            minPosition -= 1;
            int temp = numbers[0];
            for(int i=0; i<numbers.size()-1; i++){
                numbers[i] = numbers[i+1];
            }
            numbers[numbers.size()-1] = temp;
        }
        return numbers[0];
    }
};

int main(){
//    vector<int> numbers = {3, 4, 5, 1, 2};
    vector<int> numbers = {2, 2, 2, 0, 1};
    Solution solution;
    int result = solution.minArray(numbers);
    return result;
}