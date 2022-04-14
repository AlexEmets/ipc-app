//
// Created by oleksandr.yemets on 4/11/2022.
//
#ifndef IPC_APPLICATION_CHILD_H
#define IPC_APPLICATION_CHILD_H

#include<iostream>
#include<unistd.h>
#include<csignal>
#include <cstdio>
#include <cstring>
#include <limits>
#include <sys/shm.h>
#include <sys/ipc.h>

extern size_t counter;
extern FILE *fptr;

namespace {
    constexpr char counterLastValueFileName[] = "counterLastValue";
}
void startCounter(const size_t period);

void outputValueOfCounter();

void sigintHandler(int signal);

void getValueOfCounter(char* valueString);

//returns the Shared Memory Block's ID
static int getSharedBlock(char* fileName, int size) {
    key_t key;

    key = ftok(fileName, 0);
    if(key == -1) {return -1;}
    return shmget(key, size, 0644 | IPC_CREAT);
}

char * attachMemoryBlock(char* fileName, int size);
#endif //IPC_APPLICATION_CHILD_H
