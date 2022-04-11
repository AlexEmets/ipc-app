//
// Created by oleksandr.yemets on 4/11/2022.
//

#include "child.h"

size_t counter = 0;
FILE *fptr = nullptr;

void sigintHandler(int signal) {

    fptr = fopen(counterLastValueFileName, "w");

    if(fptr == NULL) {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occurred
    }

    fprintf(fptr, "%ld", counter);
    exit(0);

}

void getValueOfCounter() {
    fptr = fopen(counterLastValueFileName, "r");
    if(fscanf (fptr, "%ld", &counter) == EOF) counter=0;
}