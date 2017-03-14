//
//	bankdatamanager.cpp
//	ds hw5
//	SORT
//

#include "bankdatamanager.h"

void BANKDATAMANAGER::Quicks(vector<USER*> &bank_list,int left,int right){

 int shit=0;
 //vector<USER*>::iterator w;
 // vector<USER*>::iterator u;
  /*  w=bank_list.begin()+left;
    u=bank_list.begin()+right;*/
   // cout<<(*w)->money<<" "<<(*(u))->money<<endl<<left<<" "<<right<<endl;
if(left<right){
    int i=left,j=right+1;
    double pivot=(bank_list[left])->money;
    do{ int fuck=0;
        do {if(i==right)break;i++;/*w=bank_list.begin()+i;*//*cout<<"i"<<endl;*/}while((bank_list[i])->money<pivot);
        do {if(j==i&&fuck==1)break;j--; /*w=bank_list.begin()+j;*/fuck==1;/*cout<<"j"<<endl;*/}while((bank_list[j])->money>pivot);
      //  cout<<"111111111"<<endl;
       // u=w-j+i;
        if(i<j)swap(bank_list[i],bank_list[j]);
    }while(i<j);
 // w=bank_list.begin()+left;
  //u=bank_list.begin()+left+1;
  if(i==j&&i==left+1){
    if((bank_list[left])->money > (bank_list[left+1])->money){
       /*cout<<(*(w+1))->money<<" "<<(*w)->money<<endl;*/
       shit=1;/*cout<<endl<<shit<<endl<<endl;*/
        swap(bank_list[left],bank_list[left+1]);
    Quicks(bank_list,left,j-1);
    }
  }

   //u=bank_list.begin()+j;

  if(shit==0){
   if(i==j&&i==left+1){
    //cout<<endl<<"2"<<endl<<endl;
    Quicks(bank_list,left+1,j);
    }
   else if(i==j&&i==right){
     //cout<<endl<<"3"<<endl<<endl;
    swap(bank_list[left],bank_list[j]);
    Quicks(bank_list,left,j-1);
   }
   else{
     //cout<<endl<<"4"<<endl<<endl;
     swap(bank_list[left],bank_list[j]);
    Quicks(bank_list,left,j-1);
    Quicks(bank_list,j+1,right);
    }
}
}
}

vector<USER*> BANKDATAMANAGER::SORTMONEY(Bank bank){
    if (bank==0){
    //cout<<"1";
     Quicks(bank1_list,0,bank1_list.size()-1);
     //cout<<"1";
     return bank1_list;
    }
      if (bank==1){
     Quicks(bank2_list,0,bank2_list.size()-1);
     return bank2_list;
      }
       if (bank==2){
     //cout<<"1";
     Quicks(bank3_list,0,bank3_list.size()-1);//cout<<"1";
     return bank3_list;
       }
}


void BANKDATAMANAGER::Quicksid(vector<USER*> &bank_list,int left,int right){

int shit=0;
 //vector<USER*>::iterator w;
 // vector<USER*>::iterator u;
  /*  w=bank_list.begin()+left;
    u=bank_list.begin()+right;*/
   // cout<<(*w)->money<<" "<<(*(u))->money<<endl<<left<<" "<<right<<endl;
if(left<right){
    int i=left,j=right+1;
    double pivot=(bank_list[left])->ID;
    do{ int fuck=0;
        do {if(i==right)break;i++;/*w=bank_list.begin()+i;*//*cout<<"i"<<endl;*/}while((bank_list[i])->ID<pivot);
        do {if(j==i&&fuck==1)break;j--; /*w=bank_list.begin()+j;*/fuck==1;/*cout<<"j"<<endl;*/}while((bank_list[j])->ID>pivot);
      //  cout<<"111111111"<<endl;
       // u=w-j+i;
        if(i<j)swap(bank_list[i],bank_list[j]);
    }while(i<j);
 // w=bank_list.begin()+left;
  //u=bank_list.begin()+left+1;
  if(i==j&&i==left+1){
    if((bank_list[left])->ID > (bank_list[left+1])->ID){
       /*cout<<(*(w+1))->money<<" "<<(*w)->money<<endl;*/
       shit=1;/*cout<<endl<<shit<<endl<<endl;*/
        swap(bank_list[left],bank_list[left+1]);
    Quicksid(bank_list,left,j-1);
    }
  }

   //u=bank_list.begin()+j;

  if(shit==0){
   if(i==j&&i==left+1){
    //cout<<endl<<"2"<<endl<<endl;
    Quicksid(bank_list,left+1,j);
    }
   else if(i==j&&i==right){
     //cout<<endl<<"3"<<endl<<endl;
    swap(bank_list[left],bank_list[j]);
    Quicksid(bank_list,left,j-1);
   }
   else{
     //cout<<endl<<"4"<<endl<<endl;
     swap(bank_list[left],bank_list[j]);
    Quicksid(bank_list,left,j-1);
    Quicksid(bank_list,j+1,right);
    }
}
}
}

vector<USER*> BANKDATAMANAGER::MERGEID(){
// vector<USER*>::iterator w;
  //vector<USER*>::iterator u;
for(int i=0;i<bank2_list.size();i++)
    {/*w=bank2_list.begin()+i;*/bank1_list.push_back(bank2_list[i]);}
for(int i=0;i<bank3_list.size();i++)
   {/*u=bank3_list.begin()+i;*/bank1_list.push_back(bank3_list[i]);}
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
