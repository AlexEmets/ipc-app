//
// Created by oleksandr.yemets on 4/11/2022.
//

#ifndef IPC_APPLICATION_PARENT_H
#define IPC_APPLICATION_PARENT_H

#include<iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <string>
#include <sys/shm.h>
#include <sys/ipc.h>

namespace {

    constexpr char kCounterLastValueFileName[] = "counterLastValue";
    constexpr char kChildProcessName[] = "child";
    constexpr char kBuildDirectoryName[] = "build";
    constexpr char kNewChildProcessStarted[] = "New child process was started!";

}

//returns the Shared Memory Block's ID
static int getSharedBlock(char* fileName, int size) {
    key_t key;

    key = ftok(fileName, 0);
    if(key == -1) {return -1;}
    return shmget(key, size, 0644 | IPC_CREAT);
}

char * attachMemoryBlock(char* fileName, int size);

namespace parent {

    // Main function for executing parent and child processes.
    // After child process is killed, parent process executes it again.
    void execute(const char * pathToChildProcess);

    // After child process is killed, it writes the last value of the counter to the file.
    // We should clear this file when the parent process is started
    void clearCounterValueFile();

}

#endif //IPC_APPLICATION_PARENT_H
