//
// Created by huangxin on 2023/9/13.
//

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

const int N = 10;
mutex mtx;
condition_variable cv;
int currentThread = 0;

void printChar(char ch, int id) {
    for (int i = 0; i < N; i++) {
        unique_lock<mutex> lock(mtx);
        if(id != currentThread) {
            cv.wait(lock);
        }
        cout << ch;
        currentThread = (currentThread + 1) % 3;
        cv.notify_all();
    }
}


int main() {
    thread threadA(printChar, 'A', 0);
    thread threadB(printChar, 'B', 1);
    thread threadC(printChar, 'C', 2);

    threadA.join();
    threadB.join();
    threadC.join();

    return 0;
}
