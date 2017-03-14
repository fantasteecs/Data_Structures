//
// PrimeChecker.cpp
// ds_hw1_warm_up
//
#include "PrimeChecker.h"

bool PRIMECHECKER::PrimeChecker(int num){
	int d,n=(int)num^0.5;
	for(d=2;d<n;d++)
    {
    if(n%d==0){return false;break;}
    }
	if(d==(n-1){return true;}
}
