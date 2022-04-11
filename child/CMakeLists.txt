project(child)

cmake_minimum_required(VERSION 3.16)



add_executable(${PROJECT_NAME}
        main.cpp
        child.cpp child.h)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(child PRIVATE Threads::Threads)