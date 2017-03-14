//
//  fileHandler.cpp
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//
#include <sstream>
#include <string.h>
#include "fileHandler.h"
using namespace std;
void FILE_HANDLER::addFileName(std::string s) {
    filelist.clear();
     treenode *cnode;
    int d=0;

    if(i>0){    //找到要放新node的地方
        cnode=&tree[0];
    while(1)
    {

        if(cnode==NULL)break;

        if(strcmp(s.c_str(), cnode->w.c_str())<0)
        {
            trannode=cnode;//trannode接cnode指的位置
         cnode=cnode->left;d=1;
        }
        else //if(strcmp(s.c_str(), cnode->w.c_str())>0)
         {
        trannode=cnode;
         cnode=cnode->right;d=2;
         }

    }
    }


    tree[i].w=s;
    tree[i].left=NULL;
    tree[i].right=NULL;



    if(i>0){//指左或指右
    if(d==1)trannode->left=&tree[i];
    else if(d==2) {trannode->right=&tree[i];}

    }


    i++;

}

bool FILE_HANDLER::searchFileName(std::string s) {
    filelist.clear();
     treenode *cnode;
    cnode=&tree[0];//currentnode指向樹根
    while(1)
    {
        if(cnode==NULL)break;
        if(strcmp(s.c_str(), cnode->w.c_str())==0)
            return true;
        else if(strcmp(s.c_str(), cnode->w.c_str())<0)
         cnode=cnode->left;
        else //if(strcmp(s.c_str(), cnode->w.c_str())>0)
         cnode=cnode->right;
    }
    return false;
}

void FILE_HANDLER::inorder(treenode *currentnode ){
    if(currentnode){
    inorder(currentnode->left);
    filelist.push_back(currentnode->w);
    inorder(currentnode->right);
    }
}
std::vector<std::string> FILE_HANDLER::getFileList() {
      treenode *cnode;
     cnode=&tree[0];
     inorder(cnode);//利用中序走訪排序
  return filelist;
   /* for (unsigned k=0; k<i; k++) {
        for (unsigned j=k+1; j<i; j++) {
            if (tree[k].w.compare(tree[j].w)>0) {
                swap(tree[k], tree[j]);
            }
        }
    }
    std::vector<std::string> finallist;
    for(int j=0;j<i;j++){
        finallist.push_back(tree[j].w);
    }
    return finallist;
    //std::vector<std::string>();*/

}
