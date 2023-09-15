//
// Created by huangxin on 2023/8/16.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

const int NUM_PRINTS = 10;
std::mutex mtx;
std::condition_variable cv;
int current = 0;

void printChar(char c) {
    for (int i = 0; i < NUM_PRINTS; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return current == (c - 'A'); });
        std::cout << c;
        current = (current + 1) % 3;
        cv.notify_all();
    }
}

int main() {
    std::thread threadA(printChar, 'A');
    std::thread threadB(printChar, 'B');
    std::thread threadC(printChar, 'C');

    threadA.join();
    threadB.join();
    threadC.join();

    std::cout << std::endl;

    return 0;
}
