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


char fileName[] = "../../parent/build/sharedFile.txt";
int sizeFile = 128;

int main(int argc, char** argv) {
    signal(SIGINT, sigintHandler);
    signal(SIGKILL, sigintHandler);
    signal(SIGTERM, sigintHandler);

    size_t period = 0;
    char* sharedMemoryPointer = attachMemoryBlock(fileName, sizeFile);
    std::cout << sharedMemoryPointer;

    if(argc>1) {
        std::cout << argv[1] << std::endl;
        getValueOfCounter(argv[1]);
    }

    std::cout << "Enter the counter period(from 1mS to 1000ms(1s)):\n";
    std::cin >> period;

    std::thread t_outputValueOfCounter(outputValueOfCounter);
    try {
        t_outputValueOfCounter.detach();

        startCounter(period);
    }catch(std::exception& exc) {
        std::cout << exc.what() << '\n' << "Terminating the child process...\n";
    }

}
