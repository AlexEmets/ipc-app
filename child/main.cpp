//
// Created by oleksandr.yemets on 4/8/2022.
//

#include<iostream>
#include<unistd.h>
#include<csignal>
#include <cstdio>
#include <cstring>
#include <thread>
#include"child.h"


void startCounter(const int period) {
    while(true)
    {
        //sleep in microseconds. // micro * 1000 == milli
        usleep(1000*period);
        counter++;
    }
}


void outputValueOfCounter() {
    while(true) {
        sleep(1);
        std::cout << "Counter: " << counter << std::endl;
    }
}

int main() {
    signal(SIGINT, sigintHandler);
    signal(SIGKILL, sigintHandler);
    signal(SIGTERM, sigintHandler);

    int period = 0;
    getValueOfCounter();

    std::cout << "Enter the counter period(from 1mS to 1s):\n";
    std::cin >> period;

    std::thread t_outputValueOfCounter(outputValueOfCounter);
    t_outputValueOfCounter.detach();

    startCounter(period);

}
