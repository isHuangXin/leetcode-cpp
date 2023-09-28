//
// Created by huangxin on 2023/9/26.
//
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int INF = 1e3;

string minWindowSubString(string A, string B) {
    unordered_map<char, int> targetFreq;
    unordered_map<char, int> windowFreq;
    for (char ch : B) {
        targetFreq[ch]++;
    }
    int left = 0;
    int minLen = INF;
    int minStart = 0;
    int count = 0;

    for (int right = 0; right < A.length(); right++) {
        char currentChar = A[right];

        if (targetFreq.find(currentChar) != targetFreq.end()) {
            windowFreq[currentChar]++;
            if (windowFreq[currentChar] <= targetFreq[currentChar]) {
                count++;
            }
        }

        while(count == B.length()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            char leftChar = A[left];
            if(targetFreq.find(leftChar) != targetFreq.end()) {
                windowFreq[leftChar]--;
                if(windowFreq[leftChar] < targetFreq[leftChar]) {
                    count--;
                }
            }
            left++;
        }
    }

    if (minLen == INF) {
        return "";
    }
    return A.substr(minStart, minLen);
}

int main() {
    string A, B;
    cin >> A >> B;

    string res = minWindowSubString(A, B);
    cout << res << endl;
    return 0;
}