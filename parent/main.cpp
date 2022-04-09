//
// Created by oleksandr.yemets on 4/8/2022.
//
#include<iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <ctime>

using std::cout; using std::endl;

int main() {
    pid_t w_pid;
    int status;
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid == 0) {
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

                if(c_pid == 0) execl("../../child/build/child", "child", NULL);

            }
            else if (WIFSIGNALED(status)) {
                std::cout << "Child process was killed."
                          << "A new child process started! " << status << '\n';

                c_pid = fork();

                if(c_pid == 0) execl("../../child/build/child", "child", NULL);

                //               system("../../child/build/child");
            }
            else if (WIFSTOPPED(status)) {
                std::cout << "Child process was stopped." << std::endl;
            }

        }

        std::cout << "Parent process is exiting because child is terminated. Bye!\n";

    }

return EXIT_SUCCESS;
}