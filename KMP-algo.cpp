// #include<iostream>
// #include<string>
// #include<cstring>
// using namespace std;

// void computeLPSArray(const char* pat,int M,int* lps);

// void KMPSearch(const char* pat, const char* txt){
//     int M=strlen(pat);
//     int N=strlen(txt);
    
//     int *lps=new int[M];
    
//     computeLPSArray(pat,M,lps);
    
//     int i=0;
//     int j=0;
//     int k=0;
//     while((N-i)>=(M-j)){
//         if(pat[j]==txt[i]){
//             j++;
//             i++;
//         }
//         if(j==M){
//             if(k==0)
//             printf("%d ",i-j);
            
//             if(k!=0)
//             printf("%d ",i-j+1);
            
//             k++;
//             j=lps[j-1];
//         }
//         else if(i<N && pat[j]!=txt[i]){
//             if(j!=0){
//                 j=lps[j-1];
//             }
//             else{
//                 i++;
//             }
//         }
//     }
// }

// void computeLPSArray(const char* pat,int M,int* lps){
//     int len=0;
//     lps[0]=0;
//     int i=1;
//     while(i<M){
//         if(pat[i]==pat[len]){
//             len++;
//             lps[i]=len;
//             i++;
//         }
//         else{
//             if(len!=0){
//                 len=lps[len-1];
//             }
//             else{
//                 lps[i]=0;
//                 i++;
//             }
//         }
//     }
// }

// int main(){
//     string text;
//     cin>>text;
//     string pattern;
//     cin>>pattern;
//     KMPSearch(pattern.c_str(),text.c_str());
//     return 0;
// }



#include <iostream>
#include <string>
using namespace std;

void ComputeLPS(string P,int M,int lps[]);

void KMPSearch(string P,string T){
  int N=T.length();
  int M=P.length();
  bool found=false;
 
  int lps[M];
 
  ComputeLPS(P,M,lps);
 
  int i=0;
  int j=0;
  while((N-i)>=(M-j)){
    if(P[j]==T[i]){
      i++;
      j++;
    }
    if(j==M){
      found=true;
      cout<<i-j<<" ";
      j=lps[j-1];
    }
    else if(i<N && P[j]!=T[i]){
      if(j!=0){
        j=lps[j-1];
      }
      else{
        i++;
      }
    }
  }
  if(!found){
    cout<<"Not Found" << endl;
  }
}

void ComputeLPS(string P,int M,int lps[]){
  int len=0;
  lps[0]=0;
 
  int i=1;
  while(i<M){
    if(P[i]==P[len]){
      len++;
      lps[i]=len;
      i++;
    }
    else{
      if(len!=0){
        len=lps[len-1];
      }
      else{
        lps[i]=0;
        i++;
      }
    }
  }
 
 
}


int main()
{
    string T="ABCDEFABCGHIABC";
    string P="BC";
    KMPSearch(P,T);
    return 0;
}