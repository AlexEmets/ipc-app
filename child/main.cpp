//
// Created by oleksandr.yemets on 4/8/2022.
//

#include<iostream>
#include<unistd.h>
#include<csignal>
#include <cstdio>
#include <cstring>
#include"child.h"


int main() {
    signal(SIGINT, sigintHandler);
    signal(SIGKILL, sigintHandler);
    signal(SIGTERM, sigintHandler);


    getValueOfCounter();

    std::cout << "Enter the counter period(from 1mS to 1s):\n";
    std::cin >> period;

    while(true)
    {
        sleep(period);
        std::cout << "Counter: " << ++counter << std::endl;
    }

}
