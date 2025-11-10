#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);

        // 构建图和入度数组
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // 初始化队列，加入所有入度为0的课程
        vector<int> zeroInDegree;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push_back(i);
            }
        }

        int completedCourses = 0;

        // 拓扑排序
        while (!zeroInDegree.empty()) {
            int course = zeroInDegree.back();
            zeroInDegree.pop_back();
            completedCourses++;

            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push_back(neighbor);
                }
            }
        }

        return completedCourses == numCourses;
    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool result = sol.canFinish(numCourses, prerequisites);
    cout << (result ? "true" : "false") << endl;
    return 0;
};
