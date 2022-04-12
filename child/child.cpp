//
// Created by oleksandr.yemets on 4/11/2022.
//

#include "child.h"

size_t counter = 0;
FILE *fptr = nullptr;

void startCounter(const size_t period) {
    while(true)
    {
        //sleep in microseconds. // micro * 1000 == milli
        usleep(1000*period);
        counter++;
        if(counter == std::numeric_limits<size_t>::max()) {
            throw std::overflow_error("Counter is overflowed!");
        }
    }
}


void outputValueOfCounter() {
    while(true) {
        sleep(1);
        std::cout << "Counter: " << counter << std::endl;
    }
}

void sigintHandler(int signal) {

    fptr = fopen(counterLastValueFileName, "w");

    if(fptr == NULL) {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occurred
    }

    fprintf(fptr, "%ld", counter);
    exit(counter);

}

void getValueOfCounter(char* valueString) {
    counter= atoi(valueString);
}