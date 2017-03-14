//
//  iRobot.cpp
//  DS_hw2_Tree
//
//  Created by mu szu-pang on 9/12/14.
//  Copyright (c) 2014 mu szu-pang. All rights reserved.
//
#include <iostream>
#include "iRobot.h"
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

void iRobot::buildMaze(string filename){
    ifstream fin;
    fin.open(filename.c_str(), ios::in);
    fin>>mazeHeight;
    fin>>mazeWidth;
    maze = new char* [mazeHeight];
    for(int i=0; i<mazeHeight; i++)
        maze[i] = new char [mazeWidth];
    for(int i=0; i<mazeHeight; i++)
        for(int j=0; j<mazeWidth; j++)
            fin>>maze[i][j];
}

void iRobot::printMaze(){
    for(int i=0; i<mazeHeight; i++){
        for(int j=0; j<mazeWidth; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}

char** iRobot::findTheTrash() {
    queue<point> unvisited;
    vector<int>route[2];//route存走過的點的座標  x座標存進route[0] y座標存進route[1]
    point* current;//現在要檢查的點


    int a,b,same;
   for(int i=1; i<mazeHeight-1; ++i){ //找S
        if(a==i)break;
        for(int j=1; j<mazeWidth-1; ++j){
          if(maze[i][j]=='S'){a=i;b=j;break;}
        }
   }
    point p0,pa;p0.a=a;p0.b=b;
    route[0].push_back(p0.a);route[1].push_back(p0.b);//把S的座標存進route裡
    unvisited.push(p0);
   while(1)
 {

      current=&(unvisited.front());
      current->around=&pa;




        if(maze[current->a-1][current->b]!='2'&&maze[current->a-1][current->b]!='3'){

         (current->around)->a=current->a-1;//上方的point
         (current->around)->b=current->b;
            unvisited.push(*current->around);

            route[0].push_back(current->a-1);
            route[1].push_back(current->b);
            if (maze[current->a][current->b]=='T')break;
            maze[current->a-1][current->b]='3';}



        if(maze[current->a+1][current->b]!='2'&&maze[current->a+1][current->b]!='3'){

            (current->around)->a=current->a+1;//下方的point
            (current->around)->b=current->b;
           unvisited.push(*current->around);

            route[0].push_back(current->a+1);
            route[1].push_back(current->b);
             if (maze[current->a+1][current->b]=='T')break;
            maze[current->a+1][current->b]='3';}



        if(maze[current->a][current->b-1]!='2'&&maze[current->a][current->b-1]!='3'){

            (current->around)->a=current->a;//左邊的point
            (current->around)->b=current->b-1;
            unvisited.push(*current->around);

            route[0].push_back(current->a);
            route[1].push_back(current->b-1);
            if (maze[current->a][current->b-1]=='T')break;
            maze[current->a][current->b-1]='3';}


        if(maze[current->a][current->b+1]!='2'&&maze[current->a][current->b+1]!='3'){

           (current->around)->a=current->a;//右邊的point
            (current->around)->b=current->b+1;
           unvisited.push(*current->around);

            route[0].push_back(current->a);
            route[1].push_back(current->b+1);
            if (maze[current->a][current->b+1]=='T')break;
            maze[current->a][current->b+1]='3';}

 unvisited.pop();
 }



  //以下把最短路徑的point改成1//
current->a=(current->around)->a;current->b=(current->around)->b;
//cout<<route[0].size()<<" "<<current->a<<" "<<current->b<<endl;
  int siz=route[0].size();

   for(int i=0;i<siz;++i){
    maze[route[0][i]][route[1][i]]='0';
   }
    maze[current->a][current->b]='T';
   while(1){
    if((current->a==a)&&(current->b==b))break;
    for(int i=siz-1;i>=0;--i){
      //cout<<1;
       if (abs(route[0][i]-current->a)==0)//前項差零
        {//cout<<1;
                if(abs(route[1][i]-current->b)==1){
                   maze[route[0][i]][route[1][i]]='1';
                    current->a=route[0][i];current->b=route[1][i];siz=i;
                }
        }


        if (abs(route[0][i]-current->a)==1)//前項差一
        {//cout<<1;
                if(abs(route[1][i]-current->b)==0){
                    maze[route[0][i]][route[1][i]]='1';
                    current->a=route[0][i];current->b=route[1][i];siz=i;
                }
        }

      }
   }
    maze[a][b]='S';
    return maze;
}
