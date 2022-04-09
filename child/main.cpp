//
// Created by oleksandr.yemets on 4/8/2022.
//

#include<iostream>
#include<unistd.h>

int main() {

    int period=0, counter=0;

    std::cout << "Enter the counter period(from 1mS to 1s):\n";
    std::cin >> period;



    while(true)
    {
        sleep(period);
        std::cout << "Counter: " << ++counter << std::endl;
    }

}
