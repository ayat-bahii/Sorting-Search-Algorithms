#include<iostream>

#include "linkedlist.h"
using namespace std;




void swap(int &val1,int &val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubblesort(linkedlist &llk){
    if(llk.size()==0){
        cout<<"Empty\n";
        return;
    }
    int n=llk.size();
    int flag=0;
   
    for(int i=0;i<n-1&&flag==0;i++){
        flag=1;
        node* current=llk.head;
        for(int j=0;j<n-i-1;j++){
            if(current->data > current->next->data){
                flag=0;
                swap(current->data,current->next->data);
            }
            current=current->next;
        }

    }
}


void selectionsort(linkedlist &llk){
    node* start=llk.head;
    int n=llk.size();
    while(start!=NULL){
        node* current=start->next;
        node* mini=start;
        while(current!=NULL){
            if(current->data < mini->data){
                mini=current;
            }
            current=current->next;
        }
        swap(start->data,mini->data);
        start=start->next;
    }
}

int binarysearch(linkedlist &llk,int val){
    int n=llk.size();
    int maxi=n-1,mini=0,mid=0,midval=0;
    while(mini<=maxi){
        mid=(maxi+mini)/2;
        midval=llk.getDataByIndex(mid);
        if(midval==val){
            return mid;
        }
        if(midval>val){
            mini=mid+1;
        }
        else{
            maxi=mid-1;
        }
    }
    return -1;
}



int main(){
    linkedlist llk;
    llk.add(5);
    llk.add(1);
    llk.add(10);
    llk.add(3);
    llk.add(9);
    //bubblesort(llk);
    selectionsort(llk);
    llk.display();
    // cout<<"\n";
    // cout<<binarysearch(llk,3);
    return 0;
}




