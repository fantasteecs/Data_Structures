//
//  fileHandler.h
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#ifndef __DS_hw3_Tree__fileHandler__
#define __DS_hw3_Tree__fileHandler__

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

class treenode{
private:

public:
    treenode* left;
    treenode* right;
    std::string w;
};

class FILE_HANDLER {
private:

public:
    void addFileName(std::string );
    bool searchFileName(std::string );

    std::vector<std::string> getFileList();
    int i=0;
    treenode *root;
    treenode *cnode;
    treenode *trannode;
    void inorder(treenode*);
    std::vector<std::string> filelist;
};

#endif /* defined(__DS_hw3_Tree__fileHandler__) */
