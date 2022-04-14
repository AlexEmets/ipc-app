//
// Created by oleksandr.yemets on 4/11/2022.
//

#include "parent.h"

void parent::execute(const char * pathToChildProcess) {

    pid_t w_pid;
    int status;
    int p[2];
    int valueOfChildCounter=0;

    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    else if (c_pid == 0) {

        //execute child process
        execl(pathToChildProcess, kChildProcessName, NULL);

    }
    else {

        while (true) {
            w_pid = waitpid(c_pid, &status, WUNTRACED);

            if (w_pid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {

                // get the value of counter from child app. (The value is returned by child application(exit(counter)))
                valueOfChildCounter = WEXITSTATUS(status);

                // int value -> char* value(to pass the value as argv parameter to child application)
                char s_valueOfChildCounter[128];
                std::sprintf(s_valueOfChildCounter, "%d", valueOfChildCounter);

                std::cout << "Child process was exited with value of counter " << valueOfChildCounter << std::endl
                          << kNewChildProcessStarted << '\n';

                c_pid = fork();

                if(c_pid == 0) execl(pathToChildProcess, kChildProcessName,
                                     s_valueOfChildCounter, NULL);

            }
            else if (WIFSTOPPED(status)) {
                std::cout << "Child process was stopped." << std::endl;
            }

        }
    }

}

char * attachMemoryBlock(char* fileName, int size) {
    int sharedBlockID = getSharedBlock(fileName, size);
    char * result;

    std::cout << "Block ID: " << sharedBlockID << std::endl;

    result = (char*)shmat(sharedBlockID, NULL, 0);
    if(result == (char*)-1) {
        return nullptr;
    }
    return result;
}

void parent::clearCounterValueFile() {
    std::ofstream ofs;
    ofs.open(kCounterLastValueFileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}


