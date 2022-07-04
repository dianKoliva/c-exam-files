#include <iostream>
#include <fstream>
#include<string>
using namespace std;

const int num=20;

string name[num]={};
string age[num]={};
string id[num]={};
string darasa[num]={};

void write(){
    ofstream mine("kols.txt");
     for(int i=0;i<num;i++){
        if(id[i]!="\0"){
            mine<<"#"<<id[i]<<":"<<name[i]<<"*"<<age[i]<<"@"<<darasa[i]<<"%"<<endl;
        }
        else{
            continue;
        }
     }

}

void read(){
    string line;
    ifstream mine("kols.txt");

    string idV;
    string nameV;
    string ageV;
    string darasaV;
    int i=0;
   while(getline(mine,idV,',')){

getline(mine,nameV,',');
getline(mine,ageV,',');
getline(mine,darasaV,'\n');

 name[i]=nameV;
 age[i]=ageV;
 id[i]=idV;
darasa[i]=darasaV;
i++;
   }
}

void deleter(string id_wanted){
    int found=-1;

for(int i=0;i<num;i++){

    if(id[i]==id_wanted){
        found=i;
    }
}
if(found==-1){
    cout<<endl<<" No user with the provided Id";
}
else{
    name[found]="";
  id[found]="";
  darasa[found]="";
  age[found]="";
    cout<<endl<<"Student deleted";
}


}

void display(){
cout<<endl<<"Current records";
   for(int i=0;i<num;i++){

       if(id[i]!="\0"){
           cout<<endl<<"Name: "<<name[i]<<" Id: "<<id[i]<<endl;
       }

    }

}

void add(string nameV,string ageV, string idV, string darasaV){
int empty=0;
for(int i=0;i<num;i++){
    if(id[i]=="\0"){
        empty=i;
        break;
    }

}
name[empty]=nameV;
age[empty]=ageV;
id[empty]=idV;
darasa[empty]=darasaV;
}



int main(){
read();
}
