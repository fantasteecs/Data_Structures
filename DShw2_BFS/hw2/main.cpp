//
//  main.cpp
//  DS_hw2_Tree
//
//  Created by mu szu-pang on 9/12/14.
//  Copyright (c) 2014 mu szu-pang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string.h>
#include "iRobot.h"
using namespace::std;

int main(int argc, const char * argv[])
{
    cout<<"DS HW2 iRobot"<<endl;
    iRobot example;
    char** finalMaze;

    clock_t start_time,end_time;
    start_time=clock();

    // your program start here
    // code below is used as reference
    // it's possible check file at any time

    example.buildMaze("Maze3.txt");
    finalMaze = example.findTheTrash();
    example.printMaze();


    // your program end here

    end_time=clock();
    cout<<"Total use "<<(double)(end_time-start_time)/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}

