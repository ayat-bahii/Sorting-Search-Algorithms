#include<iostream>
#include "stack.h"
#include "linkedlist.h"
using namespace std;


int fact(int);
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
        for(int j=0;j<n-i-1;j++){
            if(llk.getDataByIndex(j)>llk.getDataByIndex(j+1)){
                flag=0;
                swap(llk.getDataByIndex(j),llk.getDataByIndex(j+1));
            }
        }
    }
}

void selectionsort(linkedlist &llk){
    int mini=0;
    int n=llk.size();
    for(int i=0;i<n-1;i++){
        mini=i;
        for(int j=i+1;j<n;j++){
            if(llk.getDataByIndex(j)<llk.getDataByIndex(mini)){
                mini=j;
            }
        }
        swap(llk.getDataByIndex(i),llk.getDataByIndex(mini));
    }
}

int binarysearch(linkedlist llk,int val){
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
    // cout<<fact(5);
    linkedlist llk;
    llk.add(5);
    llk.add(1);
    llk.add(10);
    llk.add(3);
    llk.add(9);
    //bubblesort(llk);
    //selectionsort(llk);
    llk.display();
    cout<<"\n";
    cout<<binarysearch(llk,3);
    return 0;
}




int fact(int n){
    stack s(n);
    int val1=0,val2=0,newval=0;
    for(int i=n;i>=1;i--){
        s.push(i);
    }
    for(int i=0;i<n-1;i++){
        val1=s.pop();
        val2=s.pop();
        newval=val1*val2;
        s.push(newval);
    }
    return s.pop();
}