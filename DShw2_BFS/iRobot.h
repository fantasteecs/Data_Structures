//
//  iRobot.h
//  DS_hw2_Tree
//
//  Created by mu szu-pang on 9/12/14.
//  Copyright (c) 2014 mu szu-pang. All rights reserved.
//

#ifndef __DS_hw2_iRobot__
#define __DS_hw2_iRobot__

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class iRobot {
private:
    int mazeHeight, mazeWidth;
    char** maze;
public:
    void buildMaze(string);
    void printMaze();
    char** findTheTrash();
    iRobot() {}
};

class point{
public:
    int a,b;//x,y®y¼Ð
    point* around;//¥|©Pªºpoint

};

#endif
