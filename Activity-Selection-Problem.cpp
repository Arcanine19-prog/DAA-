#include<iostream>
#include<climits>
#include<cmath>
#include<cstdlib>
using namespace std;

typedef struct activity{
    int start,end,no;
}activity;

int compare(void const* a1,void const* a2){
    activity* x=(activity*)a1;
    activity* y=(activity*)a2;
    if(x->end<y->end){return -1;}
    else if(x->end>y->end){return 1;}
    return 0;
}

void activitySelection(activity* a,int n,int* ans,int* size){
    qsort(a,n,sizeof(activity),compare);
    int ind=0,end;
    ans[ind++]=a[0].no;
    end=a[0].end;
    for(int i=1;i<n;i++){
        if(a[i].start>=end){
            ans[ind++]=a[i].no;
            end=a[i].end;
        }
    }
    *size=ind;
}

int main(){
    int s[]={1,2,3,6,5,8};
    int e[]={3,5,9,8,7,9};
    int n=sizeof(e)/sizeof(int);
    activity* a=new activity[n];
    for(int i=0;i<n;i++){
        a[i].start=s[i];
        a[i].end=e[i];
        a[i].no=i+1;
    }
    int* ans=new int[n];
    int size=0;
    activitySelection(a,n,ans,&size);
    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }
    delete[] a;
    return 0;
}