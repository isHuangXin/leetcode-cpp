//
// Created by huangxin on 2023/9/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 交换数组中两个元素的位置
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

// 选择最后一个元素作为分区点，将小于分区点的元素移动到左边，大于分区点的元素移动到右边
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // 选择最后一个元素作为分区点
        int i = (low - 1); // 初始化较小元素的索引

        for (int j = low; j <= high - 1; j++) {
            // 如果当前元素小于等于分区点，将它交换到较小元素的位置
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        // 最后交换分区点与较小元素的下一个元素
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // 快速排序主函数
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // 找到分区点索引
            int pivotIndex = partition(arr, low, high);

            // 递归地对分区点左边和右边的子数组进行排序
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 1};
    Solution solution;
    vector<int> res = solution.sortArray(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}