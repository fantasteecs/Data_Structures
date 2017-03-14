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
    int d=0;

    if(i>0){
        cnode=root;
    while(1)
    {

        if(cnode==NULL)break;

        if(strcmp(s.c_str(), cnode->w.c_str())<0)
        {
            trannode=cnode;
         cnode=cnode->left;d=1;
        }
        else //if(strcmp(s.c_str(), cnode->w.c_str())>0)
         {
        trannode=cnode;
         cnode=cnode->right;d=2;
         }

    }
    }

   cnode= new treenode;
    cnode->w=s;
    cnode->left=NULL;
    cnode->right=NULL;
   if(i==0)root=cnode;


    if(i>0){
    if(d==1)trannode->left=cnode;
    else if(d==2) {trannode->right=cnode;}

    }


    i++;

}

bool FILE_HANDLER::searchFileName(std::string s) {
    filelist.clear();
    cnode=root;
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
     cnode=root;
     inorder(cnode);
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
