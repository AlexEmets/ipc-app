//
// Created by oleksandr.yemets on 4/8/2022.
//
#include<iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <cstring>
#include "parent.h"
#include <sys/mman.h>
#define MSGSIZE 16


//../../child/build/child
char fileName[] = "sharedFile.txt";
int sizeFile = 128;
int main(int argc, char * argv[]) {

    char* sharedMemoryPointer = attachMemoryBlock(fileName, sizeFile);


    char messageToBlock[] = "aboba!";
    std::cout << "Printed to block: " << messageToBlock << std::endl;
    strncpy(sharedMemoryPointer, messageToBlock, sizeFile);
    //if(argc < 2) return std::cout << "Path to child application wasn't entered:(\n"
      //                               "Please, pass the relative/absolute path in cmd argument\n",0;

    //parent::execute(argv[1]);

    return 0;
}