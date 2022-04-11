//
// Created by oleksandr.yemets on 4/8/2022.
//
#include<iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <ctime>
#include <cstdio>
#include <fstream>
#include "parent.h"
#define MSGSIZE 16


int main() {

    parent::clearCounterValueFile();
    parent::execute();

    return 0;
}