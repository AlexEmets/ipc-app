//
// Created by oleksandr.yemets on 4/11/2022.
//

#include "child.h"

int counter = 0;
FILE *fptr = nullptr;

void sigintHandler(int signal) {

    fptr = fopen(counterLastValueFileName, "w");

    if(fptr == NULL) {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occurred
    }

    fprintf(fptr, "%d", counter);
    exit(0);

}

void getValueOfCounter() {
    fptr = fopen(counterLastValueFileName, "r");
    if(fscanf (fptr, "%d", &counter) == EOF) counter=0;
}