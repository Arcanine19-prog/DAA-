// #include<iostream>
// using namespace std;
// #include<climits>

// int minimum(int a,int b){
//     if(a<b)return a;
//     return b;
// }

// void reco(int* a,int i,int j,int** dp){
//     if(j==i+1){
//         dp[i][j]=0;
//         return;
//     }
//     if(dp[i][j]!=-1)return;
    
//     int min=INT_MAX;
//     for(int k=i+1;k<j;k++){
//         if(dp[i][k]==-1){
//             reco(a,i,k,dp);
//         }
//         if(dp[k][j]==-1){
//             reco(a,k,j,dp);
//         }
//         int cost=dp[i][k]+dp[k][j]+(a[i]*a[k]*a[j]);
//         min=minimum(min,cost);
//     }
//     dp[i][j]=min;
// }

// int main(){
//     int n;
//     cin>>n;
//     int arr[n+1];
//     int** dp=new int*[n+1];
//     for(int i=0;i<=n;i++){
//         dp[i]=new int[n+1];
//     }
//     for(int i=0;i<=n;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             dp[i][j]=-1;
//         }
//     }
//     reco(arr,0,n,dp);
//     cout<<dp[0][n]<<endl;
    
//     return 0;
    
// }


#include<iostream>
using namespace std;
#include <climits>
int minimum(int a,int b){
    if(a<b){return a;}
    return b;
}
void reco(int* a,int i,int j,int** dp){
    if(j==i+1){return;}
    int mini=INT_MAX;
    for(int k=i+1;k<j;k++){
        if(dp[i][k]==0){reco(a,i,k,dp);}
        if(dp[k][j]==0){reco(a,k,j,dp);}
        int cost=dp[i][k]+dp[k][j]+(a[i]*a[k]*a[j]);
        mini=minimum(mini,cost);
    }
    dp[i][j]=mini;
}
int main(){
    // int a[]={311,311,414,373,100,103,125,311,103,125,311,414,373,100,125,311,414,373,100,103,125,311};
    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(a[0]);
    int** dp=new int*[n];
    for(int i=0;i<n;i++){
        *(dp+i)=new int[n];
       
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    reco(a,0,n-1,dp);
    cout<<dp[0][n-1]<<endl;
    return 0;
}

