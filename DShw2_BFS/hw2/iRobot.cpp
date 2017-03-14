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
   // vector<point> visited;
    vector<int>route[2];
    //int key[2];
     int a,b,same,g=0;
   for(int i=1; i<mazeHeight-1; ++i){
        if(a==i)break;
        for(int j=1; j<mazeWidth-1; ++j){
          if(maze[i][j]=='S'){a=i;b=j;break;}
        }
   }
  //cout<<a<<b<<endl;
    point p0,pa;p0.a=a;p0.b=b;
    point* current;
   //key[0]=a;key[1]=b;
   //route.push_back(key);
    route[0].push_back(p0.a);route[1].push_back(p0.b);
  //int ds=0;
    // unvisited.push_back(p0);
   unvisited.push(p0);
   while(1)
 {
   // !unvisited.empty()
      current=&(unvisited.front());
      current->around=&pa;//設定"上"
      if (maze[current->a][current->b]=='T')break;
  //(current->up)->direction=1;
 // (current->down)->direction=2;
  //(current->down)->visit=0;
  //(current->left)->direction=3;
  //(current->left)->visit=0;
  //(current->right)->direction=4;
       same=0;
     for (int i=route[0].size()-1;i>(route[0].size())/2;--i){//檢查是否相同
        if((current->a)-1==route[0][i]&&current->b==route[1][i]){
                same=1;break;}}


    if(same==0){
       //cout<<1;
        if(maze[current->a-1][current->b]!='2'){
           // unvisited.push_back(*current->up);
            // current->up=&pu;//設定"上"
         (current->around)->a=current->a-1;
         (current->around)->b=current->b;
            unvisited.push(*current->around);
          // key[0]=(current->up)->a;key[1]=(current->up)->b;route.push_back(key);
            route[0].push_back(current->a-1);
            route[1].push_back(current->b);}}


     same=0;
      for (int i=route[0].size()-1;i>(route[0].size())/2;--i){//檢查是否相同
        if(current->a+1==route[0][i]&&current->b==route[1][i]){
                same=1;break;}}

    if(same==0){

        if(maze[current->a+1][current->b]!='2'){

            //unvisited.push_back(*current->down);
           // current->up=&pu;
            (current->around)->a=current->a+1;
            (current->around)->b=current->b;
           unvisited.push(*current->around);
          //cout<<(current->down)->b<<" ";
           // key[0]=(current->down)->a;key[1]=(current->down)->b;route.push_back(key);
            route[0].push_back(current->a+1); //cout<<(current->down)->b<<endl;
            route[1].push_back(current->b);/*cout<<(current->down)->b<<" "<<route[1][1]<<endl;*/}}


  same=0;
     for (int i=route[0].size()-1;i>(route[0].size())/2;--i){//檢查是否相同
        if(current->a==route[0][i]&&current->b-1==route[1][i]){
                same=1;break;}}

    if(same==0){

        if(maze[current->a][current->b-1]!='2'){
           // unvisited.push_back(*current->left);
           // current->up=&pu;
            (current->around)->a=current->a;
            (current->around)->b=current->b-1;
            unvisited.push(*current->around);
            route[0].push_back(current->a);
            route[1].push_back(current->b-1);}}


   same=0;
      for (int i=route[0].size()-1;i>(route[0].size())/2;--i){//檢查是否相同
        if(current->a==route[0][i]&&current->b+1==route[1][i]){
                same=1;break;}}

    if(same==0){

        if(maze[current->a][current->b+1]!='2'){
            //unvisited.push_back(*current->right);
            //current->up=&pr;
           (current->around)->a=current->a;
            (current->around)->b=current->b+1;
           unvisited.push(*current->around);
            // cout<<current->right->a<<" "<<current->right->b<<endl;
            route[0].push_back(current->a);
            route[1].push_back(current->b+1);}}
   // visited.push_back(p0);
   // g++;
 unvisited.pop();
 }cout<<route[0].size()<<endl;
  // cout<<current->a<<" "<<current->b<<" "<<a<<" "<<b<<" "<<route[0][0]<<" "<<route[1][0]<<endl;//最後點
//cout<<route[0][1]<<route[1][1]<<endl;



  //以下把最短路徑改成1//

  int siz=route[0].size();
   while(1){
    if((current->a==a)&&(current->b==b))break;
    for(int i=0;i<siz;++i){
    //cout<<1;
   // cout<<i;
       if (abs(route[0][i]-current->a)==0)//前項差零
        {//cout<<1;
           // cout<<i<<" "<<current->a<<endl;
                if(abs(route[1][i]-current->b)==1){//cout<<1;
                   maze[route[0][i]][route[1][i]]='1';
                    current->a=route[0][i];current->b=route[1][i];siz=i;
                }
        }


        if (abs(route[0][i]-current->a)==1)//前項差一
        {//cout<<2;
            //cout<<i<<" "<<route[0][i]<<" "<<current->a<<" "<<route[1][1]<<" "<<current->b<<endl;
                if(abs(route[1][i]-current->b)==0){//cout<<3;
                    maze[route[0][i]][route[1][i]]='1';
                    current->a=route[0][i];current->b=route[1][i];siz=i;
                }
        }
      }
   }
    maze[a][b]='S';
    return maze;
}
