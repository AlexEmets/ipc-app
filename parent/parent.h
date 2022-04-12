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

namespace {

    constexpr char counterLastValueFileName[] = "counterLastValue";
    constexpr char childProcessName[] = "child";
    constexpr char buildDirectoryName[] = "build";
    constexpr char mNewChildProcessStarted[] = "New child process was started!";

}


namespace parent {

    // Main function for executing parent and child processes.
    // After child process is killed, parent process executes it again.
    void execute();

    // After child process is killed, it writes the last value of the counter to the file.
    // We should clear this file when the parent process is started
    void clearCounterValueFile();

}

#endif //IPC_APPLICATION_PARENT_H
