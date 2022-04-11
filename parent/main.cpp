//
// Created by oleksandr.yemets on 4/8/2022.
//
#include<iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <ctime>
#include <cstdio>
#include <fstream>
#define MSGSIZE 16

using std::cout; using std::endl;

constexpr char counterLastValue[] = "counterLastValue";

int main() {

    std::ofstream ofs;
    ofs.open(counterLastValue, std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    pid_t w_pid;
    int status;
    int p[2];

    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid == 0) {
        //TODO: replace first argument with a constant
        execl("../../child/build/child", "child", NULL);

    }
    else {
        std::cout << "CHILD's PID=" << c_pid << '\n';

        while (true) {
            w_pid = waitpid(c_pid, &status, WUNTRACED);

            if (w_pid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                std::cout << "Child process was exited." << std::endl
                          << "A new child process started! " << '\n';

                c_pid = fork();
                //TODO: replace first argument with a constant
                if(c_pid == 0) execl("../../child/build/child", "child", NULL);

            }
            else if (WIFSIGNALED(status)) {
                std::cout << "Child process was killed."
                          << "A new child process started! " << status << '\n';

                c_pid = fork();
                //TODO: replace first argument with a constant
                if(c_pid == 0) execl("../../child/build/child", "child", NULL);

            }
            else if (WIFSTOPPED(status)) {
                std::cout << "Child process was stopped." << std::endl;
            }

        }


    }

    return EXIT_SUCCESS;
}