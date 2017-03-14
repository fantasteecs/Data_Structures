
#include "cycleDetection.h"

void Graph::parseFile(string filename) {
    ifstream fin;
    fin.open(filename.c_str(), ios::in);
    string name1, name2;
    Vertex *vptr1, *vptr2;
    while(!fin.eof()){
        fin>>name1;
        fin>>name2;

        vptr1 = checkNode(name1);
        vptr2 = checkNode(name2);
        vptr1->connectList.push_back(vptr2);
    }
    fin.close();
}

Vertex* Graph::checkNode(string name){
    Vertex* vptr;
    map<string,Vertex*>::iterator it;

    it = nMap.find(name);
    if(it != nMap.end()) return (*it).second;

    vptr = new Vertex(name);
    nMap.insert( pair<string,Vertex*>(name,vptr));
    nodeList.push_back(vptr);
    return vptr;
}

void Graph::dfs(Vertex *a){
//if(w==1)exit;
a->flag=1;
for(int i=0;i<a->connectList.size();++i){
   // cout<<a->name<<" "<<a->connectList.size()<<" ";
   //cout<<(a->connectList[i])->name<<" ";
   //cout<<strcmp("4","1");
    if(strcmp((a->connectList[i]->name).c_str(),(tran->name).c_str())==0){/*cout<<'1'<<" ";*/w=1;break;}
    else if(a->connectList[i]->flag!=1){/*cout<<'2'<<" ";*/dfs(a->connectList[i]);if(w==1)break;}

}
}

bool Graph::cycleDetection() {
  // cout<<nodeList.size();
    for(int i=0;i<nodeList.size();++i){
        tran=checkNode(nodeList[i]->name);
        dfs(checkNode(nodeList[i]->name));
        if(w==1)return 1;
    }
//cout<<'1';
    return 0;
}


