using namespace std;
#include <iostream>

int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
int n=sizeof(arr)/sizeof(arr[0]);

struct Node{
    string name;
    int age;
    Node *next;
}*head=NULL;

struct Node *last;
struct Node *newNode;


void sort(){
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

        if(arr[j]>arr[j+1]){
            int hold=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=hold;

        }

    }
}


for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}

}


void linked_lists(int age, string name){

if(head==NULL){
    newNode=new Node;
    newNode->age;
    newNode->name=name;
    head=newNode;
}

else{

}



}
int main(){


}

