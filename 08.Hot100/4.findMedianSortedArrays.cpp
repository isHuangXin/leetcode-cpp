//
// Created by huangxin on 2023/9/28.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) {
            // 确保数组1一定最短
            return findMedianSortedArrays(nums2, nums1);
        }
        int Lmax1, Lmax2, Rmin1, Rmin2, c1, c2, lo = 0, hi = 2*n;
        while ()

    }
};


int main () {
    vector<int> num1 = {1, 2};
    vector<int> num2 = {2};

    vector<int> num3 = {1, 2};
    vector<int> num4 = {3, 4};

    Solution solution;
    int res12 = solution.findMedianSortedArrays(num1, num2);
    cout << res12 << endl;

    int res34 = solution.findMedianSortedArrays(num3, num4);
    cout << res34 << endl;

    return 0;
}