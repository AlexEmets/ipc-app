# ipc-app

### Project agenda
Project is consist of two applications: `parent` and `child`. When the parent process
starts, it also starts the `child` process and observes the state of `child` application.
When `child` executable is terminated or crashed, it's immediately executed by `parent` application 

#### Full task conditions you can find in `taskConditions.pdf` file in the `materials/` folder of this project

### How to test
1. `Compile child` subproject:
   - cd child/
   - mkdir build(!!this name is obligatory and hardcoded inside this version of application!!)
   - cd build/
   - cmake ..
   - cmake --build .
2. `Compile and execute parent` subproject:
    - cd parent/
    - mkdir build(!!this name is obligatory and hardcoded inside this version of application!!)
    - cd build/
    - cmake ..
    - cmake --build .
    - ./parent

After `parent` process is executed, you can `input the period` of counter in `child` process(from 1ms to 1000ms). 
When number is entered you'll see the value of counter printed in stdout every second. The value of counter depends on period you entered.

Now you maybe want to `kill the child` process by open one more terminal and write `kill <pid>`, where `<pid>` is PID of child process(can be obtained by `ps -ef` command).
After child process is killed, new process will be started by parent application.

### OS/environment
Application was tested inside ubuntu:20.04 based docker container.

### Technology used
- g++
- CMake
- Docker
- gcc(posix compliant system calls)
- bash
    

