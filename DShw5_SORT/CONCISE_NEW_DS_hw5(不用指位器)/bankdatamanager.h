//
//	bankdatamanager.h
//	ds hw5
//	SORT
//

#ifndef __DS_hw5_Sort__BANKDATAMANAGER__
#define __DS_hw5_Sort__BANKDATAMANAGER__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "user.h"
#define LENG_MAX 150000000

using namespace std;

class BANKDATAMANAGER{
	public:
		BANKDATAMANAGER(){}
		~BANKDATAMANAGER(){}
		void Parser(const char* name);
		void ParseBank(vector<USER*> &bank_list, const char* name, char* &in_str, char* &in_res);
		void CLEAR();
		vector<USER*> SORTMONEY(Bank bank);
		vector<USER*> MERGEID();
		void Quicks(vector<USER*> &,int left,int right);
    	void Quicksid(vector<USER*> &,int left,int right);


	private:
		USER* user;
		vector<USER*> bank1_list,bank2_list,bank3_list, merge_list;

};


#endif
