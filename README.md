# ipc-app

### Conditions 

  - Use GIT (GitHub) and just share the link to project with implementation
  
  - Project should be base on CMake
  - All interfaces should be POSIX compliant
  - Target OS: Linux
  - Language: C/C++11
  - Usage of RAII idioms (Nice to have)

Task:
Create 2 applications:

### Requirement#1:

First application "Parent" should create a new process "Child" and re-start the "Child" process in
case it crashes (or can be killed by SIGTERM from console).

### Requirement#2:

During normal flow a "Child" process will increase internal counter with period from 1mS to 1S
(period should be possible to set via command line argument)

### Requirement#3:

In case "Child" process becomes terminated, it shall be restarted by "Parent" process and the
counter should continue from the previous successful value. (The result should be clearly visible
on console with period 1S in case some printing done in stdout)
Output:
1) Output from console (can be stored in file) with:
- Starting “Parent” process (counting period 1 Sec);
- "Child" process log counter’s value in stdout
- "Child" process killed by SIGTERM from console and re-started by "Parent" process
(should be visible hello message during starting of "Child" )
- "Child" process should continue counting after restart
2) Link to source code in GitHub/Gitlab
