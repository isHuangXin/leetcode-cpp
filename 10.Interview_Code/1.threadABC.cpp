//
// Created by huangxin on 2023/9/24.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int count = 0;
const int max_count = 10;

void printChar(char ch, int target_count) {
    for (int i = 0; i < max_count; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        while (count % 3 != target_count) {
            cv.wait(lock);
        }
        std::cout << ch;
        count++;
        cv.notify_all();
    }
}

int main() {
    std::thread threadA(printChar, 'A', 0);
    std::thread threadB(printChar, 'B', 1);
    std::thread threadC(printChar, 'C', 2);

    threadA.join();
    threadB.join();
    threadC.join();

    std::cout << std::endl;

    return 0;
}
