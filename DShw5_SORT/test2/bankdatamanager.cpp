//
//	bankdatamanager.cpp
//	ds hw5
//	SORT
//


#include "bankdatamanager.h"


vector<USER*> &BANKDATAMANAGER::SORTMONEY(Bank bank){

}




vector<USER*>& BANKDATAMANAGER::MERGEID(){

}




void BANKDATAMANAGER::CLEAR(){
	bank1_list.clear();
	bank2_list.clear();
	bank3_list.clear();
	merge_list.clear();
}



void BANKDATAMANAGER::Parser(const char* name){
	char *in_str = new char[20];
	char *in_res = new char[20];
	strncpy(in_str, name, 5);
	in_str[5]='\0';
	if( !strcmp(in_str, "bank1") ){ ParseBank(bank1_list, name, in_str, in_res); }
	else if( !strcmp(in_str, "bank2") ){ ParseBank(bank2_list, name, in_str, in_res); }
	else { ParseBank(bank3_list, name, in_str, in_res); }
}

void BANKDATAMANAGER::ParseBank(vector<USER*> &bank_list, const char* name, char* &in_str, char* &in_res){
	ifstream fin(name, ios::in);
	if(!fin) cout << name << " does not exist!!!!!!!!" << endl;
	while(fin.getline(in_str, LENG_MAX)){
		user = new USER();
		in_res = strtok(in_str, " ");
		user->ID = atoi(in_res);
		in_res = strtok(NULL, " ");
		user->money = atof(in_res);
		bank_list.push_back(user);
	}
	fin.close();
}
