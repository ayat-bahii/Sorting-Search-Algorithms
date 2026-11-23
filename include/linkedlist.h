#ifndef LINKEDLIST_H
#define LINKEDLIST_H



struct node{
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        next=prev=NULL;
    }
};

class linkedlist{
    public:
    node* head;
    node* tail;
    linkedlist(){
        head=tail=NULL;
    }
    void add(int data);
    int size();
    void display();
    int& getDataByIndex(int index);
  

};

#endif