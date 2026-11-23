#include<iostream>
#include "linkedlist.h"
using namespace std;

void linkedlist::add(int data){
    node* newNode=new node(data);
    if(head==NULL){
        head=tail=newNode;
        newNode->next=NULL;
         newNode->prev=NULL;
    }
    else{
        tail->next=newNode;
        newNode->next=NULL;
        newNode->prev=tail;
        tail=newNode;
    }
}

int linkedlist::size(){
    node* current=head;
    int counter=0;
    if(current==NULL)return 0;
    while(current!=NULL){
        counter++;
        current=current->next;
    }
    return counter;
}

void linkedlist::display(){
    node* current=head;
    if(current==NULL)cout<<"Empty";
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
}

int& linkedlist::getDataByIndex(int index){
    node* current=head;
    int count=0;
    while(current!=NULL){
        if(count==index){
            return current->data;
        }
        count++;
        current=current->next;
    }
    throw out_of_range("Index out of range");
}
