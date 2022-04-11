//
// Created by oleksandr.yemets on 4/8/2022.
//

#include<iostream>
#include<unistd.h>
#include<csignal>
#include <cstdio>
#include <cstring>

static int period=0, counter=0;
FILE *fptr;
constexpr char counterLastValueFileName[] = "counterLastValue";


static void sigintHandler(int signal) {

    fptr = fopen(counterLastValueFileName, "w");

    if(fptr == NULL) {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occurred
    }

    fprintf(fptr, "%d", counter);
    exit(0);


    close(fptr);
}

int main() {
    signal(SIGINT, sigintHandler);
    signal(SIGKILL, sigintHandler);
    signal(SIGTERM, sigintHandler);


    fptr = fopen(counterLastValueFileName, "r");
    if(fscanf (fptr, "%d", &counter) == EOF) counter=0;

    std::cout << "Enter the counter period(from 1mS to 1s):\n";
    std::cin >> period;

    while(true)
    {
        sleep(period);
        std::cout << "Counter: " << ++counter << std::endl;
    }

}
