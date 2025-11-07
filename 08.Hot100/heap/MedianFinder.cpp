#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;   // max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap for the upper half
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        // Add the new number to the appropriate heap
        // 为什么要这样分配？因为我们希望 maxHeap 中的所有元素都小于等于 minHeap 中的所有元素
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        // 为什么这样调整？因为我们希望两个堆的大小差不超过 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
      if (maxHeap.size() > minHeap.size()) {
          return maxHeap.top();
      } else {
          return (maxHeap.top() + minHeap.top()) / 2.0;
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
