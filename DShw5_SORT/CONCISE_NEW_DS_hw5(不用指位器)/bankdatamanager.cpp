//
//	bankdatamanager.cpp
//	ds hw5
//	SORT
//

#include "bankdatamanager.h"

void BANKDATAMANAGER::Quicks(vector<USER*> &bank_list,int left,int right){

 int shit=0;

if(left<right){
    int i=left,j=right+1;
    double pivot=(bank_list[left])->money;
    do{ int fuck=0;
        do {if(i==right)break;i++;}while((bank_list[i])->money<pivot);//找不到比pivot大的就break
        do {if(j==i&&fuck==1)break;j--;fuck==1;}while((bank_list[j])->money>pivot);//重複多次大的do while後，i j會交錯，會有i=j的情形發生，所以設參數fuck避開

        if(i<j)swap(bank_list[i],bank_list[j]);
    }while(i<j);//當j在左 i在右時跳出迴圈

  if(i==j&&i==left+1){//i j都在pivot右邊一格 (即 找不找不到比pivot小的)    或只剩兩個數字
    if((bank_list[left])->money > (bank_list[left+1])->money){//只剩兩個數字時 才有可能發生

       shit=1;
        swap(bank_list[left],bank_list[left+1]);
    Quicks(bank_list,left,j-1);//好像可以不寫這行
    }
  }



  if(shit==0){//shit=1則略過，不重複進入條件式中
   if(i==j&&i==left+1){//剩下 找不到比pivot小的情況(包含只剩兩個數字的情況)
    Quicks(bank_list,left+1,j);
    }
   else if(i==j&&i==right){//找不到比pivot大的情況

    swap(bank_list[left],bank_list[j]);
    Quicks(bank_list,left,j-1);
   }
   else{//其他

     swap(bank_list[left],bank_list[j]);
    Quicks(bank_list,left,j-1);
    Quicks(bank_list,j+1,right);
    }
}
}
}

vector<USER*> BANKDATAMANAGER::SORTMONEY(Bank bank){
    if (bank==0){

     Quicks(bank1_list,0,bank1_list.size()-1);

     return bank1_list;
    }
      if (bank==1){
     Quicks(bank2_list,0,bank2_list.size()-1);
     return bank2_list;
      }
       if (bank==2){

     Quicks(bank3_list,0,bank3_list.size()-1);
     return bank3_list;
       }
}


void BANKDATAMANAGER::Quicksid(vector<USER*> &bank_list,int left,int right){

int shit=0;

if(left<right){
    int i=left,j=right+1;
    double pivot=(bank_list[left])->ID;
    do{ int fuck=0;
        do {if(i==right)break;i++;}while((bank_list[i])->ID<pivot);
        do {if(j==i&&fuck==1)break;j--;fuck==1;}while((bank_list[j])->ID>pivot);

        if(i<j)swap(bank_list[i],bank_list[j]);
    }while(i<j);

  if(i==j&&i==left+1){
    if((bank_list[left])->ID > (bank_list[left+1])->ID){

       shit=1;
        swap(bank_list[left],bank_list[left+1]);
    Quicksid(bank_list,left,j-1);
    }
  }



  if(shit==0){
   if(i==j&&i==left+1){

    Quicksid(bank_list,left+1,j);
    }
   else if(i==j&&i==right){

    swap(bank_list[left],bank_list[j]);
    Quicksid(bank_list,left,j-1);
   }
   else{

     swap(bank_list[left],bank_list[j]);
    Quicksid(bank_list,left,j-1);
    Quicksid(bank_list,j+1,right);
    }
}
}
}

vector<USER*> BANKDATAMANAGER::MERGEID(){

for(int i=0;i<bank2_list.size();i++)
    {bank1_list.push_back(bank2_list[i]);}
for(int i=0;i<bank3_list.size();i++)
   {bank1_list.push_back(bank3_list[i]);}
    Quicksid(bank1_list,0,bank1_list.size()-1);
  return bank1_list;
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
