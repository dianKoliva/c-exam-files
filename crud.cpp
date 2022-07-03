#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int maxrow=20;
 string EmpName[maxrow]={};
 string EmpId[maxrow]={};
 void ListRecord(){
    cout<<"\n\tCurrent Records(s)"<<endl;
    cout<<"\t====================================================="<<endl;
    int counter=0;
    cout<<"\tNO\t|\tID\t|\t  NAME\t"<<endl<<"\t=====================================================\n";

    for(int i=0;i<maxrow;i++){

        if(EmpId[i] !="\0"){
            counter++;
            cout<<"\t"<<counter<<"\t\t"<<EmpId[i]<<"\t\t  "<<EmpName[i]<<"\t\n";

        }
    }

    if(counter==0){
        cout<<"No record found!"<<endl;
    }



}

void deleteRecord(){
    string id;

    system("CLS");

    cin.ignore();
    cout<<"\n\t Employee id to delete :";
    getline(cin,id);

      int seen=-1;
    string name;

    for(int i=0;i<maxrow;i++){

        if(EmpId[i]==id){

            seen=i;
        }
    }

    if(seen==-1){
        cout<<"\n\n \t ------- Record Not found";
    }
    else{
        EmpId[seen]="";
        EmpName[seen]="";
    }

     ListRecord();


}
void updateRecords(){
system("CLS");

string id;
cin.ignore();

cout<<"\n\n\t Employee's Id to update :";
getline(cin,id);
    int seen=-1;
    string name;

    for(int i=0;i<maxrow;i++){

        if(EmpId[i]==id){

            seen=i;
        }
    }

    if(seen==-1){
        cout<<"\n\n \t ------- Record Not found";
    }
    else{
        cout<<"\n\t New name : ";
        cin>>name;
        EmpName[seen]=name;

        cout<<"\n\t Changed successfuly";

        ListRecord();
    }

}


void reader(){
   string line ;
 ifstream myfile ("data.txt");
 while(getline(myfile,line)){
        int x;
        int l=line.length();

EmpId[x]=line.substr(0,3);
EmpName[x]=line.substr(4,l-4);
x++;




//int id_start=line.find("#")+1;
	//int id_end=line.find(":");

    //int name_start =line.find(":")+1;
	//int name_end = line.find("*");



	//int  age_start= line.find("*")+1;
	//int age_end= line.find("@");

	//int darasa_start=line.find("@")+1;;
	//int darasa_end=line.find("%");

   // cout<<"Name: "<<line.substr(name_start, (name_end - name_start))<<" ";
   // cout<<"Id: "<<line.substr(id_start, (id_end - id_start))<<" ";
   // cout<<"Age: "<<line.substr(age_start, (age_end - age_start))<<" ";
   //  cout<<"Class: "<<line.substr(darasa_start, (darasa_end - darasa_start))<<" ";
   // cout<<endl<<endl;

}
}

 void saveTofile(){
 ofstream myfile("data.txt");
 for(int i=0;i<maxrow;i++){
    if(EmpId[i]=="\0"){
      continue;
    }
    else{
          myfile<<EmpId[i]+" "+EmpName[i]<<endl;

    }
 }

 }
void addRecord(){

    system("CLS");
    cout<<endl<<endl;
string name;
string empno;
string me;

cin.ignore();

cout<<"\tEmployee ID (3 numbers) :";
getline(cin,empno);
cout<<endl;

cout<<"\tEmployee Name :";
getline(cin,name);
cout<<endl;

int empty=0;


for(int x=0;x<maxrow;x++){
    if(EmpId[x]=="\0"){
empty=x;
break;

    }
}
 EmpId[empty]=empno;
        EmpName[empty]=name;

        system("CLS");


}



void searchRecord(string id){





system("CLS");

cout<<"\tSearched Record "<<endl;
cout<<"\t==============================="<<endl;
int found=-1;


for(int x=0;x<maxrow;x++){

    if(EmpId[x]==id){

            found=x;
    }
}

if(found==-1){
    cout<<"\t Search not found \t\n";
    cout<<"\t==============================="<<endl;
}
else {

    cout<<"\t"<<EmpId[found]<<"\t"<<EmpName[found];

}



}
int main(){

    reader();


   int op;

    do{
            cout<<endl<<endl;

        cout<<"\t **********MENU**********"<<endl<<endl;

        cout<<"\t 1.Create Records"<<endl;
        cout<<"\t 2.Update Records"<<endl;
        cout<<"\t 3.Delete Records"<<endl;
        cout<<"\t 4.Search Records"<<endl;
        cout<<"\t 5.Display all Records"<<endl;
        cout<<"\t 6.Exit and save textfile"<<endl<<endl;


        cout<<"\t Select option :";
        cin>>op;

        string id;

        switch(op){
        case 1:
            addRecord();
            system("CLS");
        break;

        case 2:
            updateRecords();
            system("CLS");
            break;
        case 3:
            deleteRecord();
            break;

        case 4:
            cout<<"Search by Id:";
            cin>>id;
            searchRecord(id);
            break;

        case 5:
             system("CLS");
ListRecord();
        break;
        case 6:
            cout<<"\n\n\t--------------Thanks for using our system---------------";
            saveTofile();

        }


    }while(op!=6);

}
