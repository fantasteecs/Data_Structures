//
// PrimeChecker.cpp
// ds_hw1_warm_up
//
#include "PrimeChecker.h"
#include <math.h>
//#include <iostream>
//#include <cstdlib>
//using namespace std;

bool PRIMECHECKER::PrimeChecker(int num){
	if(num%2==0)return false;
	int d,n=sqrt(num);

	//cout<<num<<" "<<endl;
	for(d=3;d<n;d=d+2)
    {
    //cout<<d<<endl;
    if(num%d==0){/*cout<<num<<" "<<d<<endl;*/return false;}
    }
    //cout<<d<<endl;
	return true;
}
