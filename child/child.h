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


extern int counter;
extern FILE *fptr;

namespace {
    constexpr char counterLastValueFileName[] = "counterLastValue";
}

void sigintHandler(int signal);
void getValueOfCounter();
#endif //IPC_APPLICATION_CHILD_H
