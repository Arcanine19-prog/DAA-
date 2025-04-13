#include<iostream>
#include<string>
using namespace std;
#define d 256

void robinKarp(string T,string P,int q){
    int n=T.length();
    int m=P.length();
    int h=1;
    int p=0;
    int t=0;
    int i,s;
    bool found=false;
    for(i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    for(i=0;i<m;i++){
        p=(d*p+P[i])%q;
        t=(d*t+T[i])%q;
    }
    for(s=0;s<=n-m;s++){
        if(p==t){
            bool match=true;
            for(i=0;i<m;i++){
                if(T[s+i]!=P[i]){
                    match=false;
                    break;
                }
            }
            if(match){
                cout<<s<<" ";
                found=true;
            }
            
        }
        if(s<n-m){
            t=(d * ( t - T[s] * h) + T[s+m] ) % q;
            if(t<0) t+=q;
        }
    }
    if(!found){
        cout<<"Access Denied"<<endl;
    }
}
int main(){
    string text;
    cin>>text;
    string pattern;
    cin>>pattern;
    robinKarp(text,pattern,101);
    return 0;
}