//
// Created by huangxin on 2023/8/18.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                int hei = height[i] > height[j]? height[i] : height[j];
                if((j-i)*hei > max_area) {
                    max_area = (j-i) * hei;
                }
            }
        }
        return max_area;
    }
};