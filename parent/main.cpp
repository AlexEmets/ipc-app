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

        int period=0, counter=0;
        std::cout << "Enter the counter period(from 1s to 3s):\n";
        std::cin >> period;

        while(true)
        {
            sleep(period);
            std::cout << ++counter << std::endl;
        }
    }
    else {
        std::cout << "CHILD's PID=" << c_pid << '\n';
        do {
            w_pid = waitpid(c_pid, &status, WUNTRACED);

            if (w_pid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status))
            {
                printf("child exited, status=%d\n", WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                std::cout << "child killed with signal " <<  status << '\n';
            }
            else if (WIFSTOPPED(status)) {
                printf("child stopped (signal %d)\n", WSTOPSIG(status));
            }

        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        std::cout << "Parent process is exiting because child is terminated. Bye!\n";

    }

    return EXIT_SUCCESS;
}
