class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash1, hash2;
        vector<int> ans;
        for (auto &i : nums1) {
            hash1[i]++;
        }
        for (auto &i : nums2) {
            hash2[i]++;
        }
        for (auto &it : hash1) {
            if (hash2.find(it.first) != hash2.end()) {
                ans.push_back(it.first);
                // ans.emplace_back(it.first);
                // emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同
                // push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）
                // emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程
            }
        }
        return ans;
    }
};