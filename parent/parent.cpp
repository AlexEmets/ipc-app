//
// Created by oleksandr.yemets on 4/11/2022.
//

#include "parent.h"

void parent::execute() {

    char childProcessCommandRelativePath[128];
    pid_t w_pid;
    int status;
    int p[2];
    int valueOfChildCounter=0;
    //get child's executable relative path.
    snprintf(childProcessCommandRelativePath, sizeof(childProcessCommandRelativePath), "%s%s%s%s%s%s",
             "../../", childProcessName, "/", buildDirectoryName, "/", childProcessName);

    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    else if (c_pid == 0) {

        //execute child process
        execl(childProcessCommandRelativePath, childProcessName, NULL);

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
                valueOfChildCounter = WEXITSTATUS(status);
                std::cout << "Child process was exited " << std::endl
                          << mNewChildProcessStarted << '\n';

                c_pid = fork();
                char s_valueOfChildCounter[128];
                std::sprintf(s_valueOfChildCounter, "%d", valueOfChildCounter);

                if(c_pid == 0) execl(childProcessCommandRelativePath, childProcessName,
                                     s_valueOfChildCounter, NULL);

            }
            else if (WIFSIGNALED(status)) {
                std::cout << "Child process was killed."
                          << mNewChildProcessStarted << status << '\n';

                c_pid = fork();


                char s_valueOfChildCounter[128];
                std::sprintf(s_valueOfChildCounter, "%d", valueOfChildCounter);

                if(c_pid == 0) execl(childProcessCommandRelativePath, childProcessName,
                                     s_valueOfChildCounter, NULL);

            }
            else if (WIFSTOPPED(status)) {
                std::cout << "Child process was stopped." << std::endl;
            }

        }
    }

}

void parent::clearCounterValueFile() {
    std::ofstream ofs;
    ofs.open(counterLastValueFileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}


