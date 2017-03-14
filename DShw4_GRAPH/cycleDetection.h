
#ifndef __DS_hw4_Cycle_Detection__
#define __DS_hw4_Cycle_Detection__

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <map>
#include "vertex.h"

using namespace std;

class Graph {
private:
    vector<Vertex*> nodeList;
    map<string,Vertex*> nMap;
     Vertex *tran;
     int w=0;
public:
    void parseFile(string);
    Vertex* checkNode(string);
    bool cycleDetection();
    void dfs(Vertex*);
    Graph() {}
    ~Graph() {}
};

#endif
