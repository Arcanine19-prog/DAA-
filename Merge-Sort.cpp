#include<iostream>
using namespace std;
#include<limits.h>

void merge(int* a,int l,int mid,int h){
    int temp[h-l+1];
    int i=l,j=mid+1,ind=0;
    while(i<=mid&&j<=h){
        if(a[i]<a[j]){temp[ind]=a[i];i++;}
        else{temp[ind]=a[j];j++;}
        ind++;
    }
    while(i<=mid){temp[ind]=a[i];ind++;i++;}
    while(j<=h){temp[ind]=a[j];ind++;j++;}
    for(int i=0;i<h-l+1;i++){
        a[l+i]=temp[i];
    }
}

void mergeSort(int* a,int l,int h){
    if(l==h){return;}
    int mid=(l+h)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,h);
    merge(a,l,mid,h);
}

int main(){
    int a[]={1,5,-8,9,10,-17,17,20};
    int n=8;
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}