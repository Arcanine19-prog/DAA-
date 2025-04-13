// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// void findMaxSubarraySum(int arr[],int n) {
//     int max_so_far = arr[0];
//     int max_ending_here = arr[0];
    
//     int start = 0, end = 0, s = 0;

//     for (int i = 1; i < n; i++) {
//         if (max_ending_here + arr[i] < arr[i]) {
//             max_ending_here = arr[i];
//             s = i;  // Start a new subarray
//         } else {
//             max_ending_here += arr[i];
//         }

//         if (max_ending_here > max_so_far) {
//             max_so_far = max_ending_here;
//             start = s;
//             end = i;
//         }
//     }

//     // Output the result
//     cout << "The given sum is found from indexes " << start << " to " << end << endl;
//     cout << "And the Subarray is: { ";
//     for (int i = start; i <= end; i++) {
//         cout << arr[i];
//         if (i < end) cout << ", ";
//     }
//     cout << " }" << endl;
    
//     cout << "Required sum between indexes of corresponding elements is: " << max_so_far << endl;
// }

// int main() {
//     int n;
//     cin >> n; // Corrected input operator

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i]; // Corrected input operator
//     }

//     findMaxSubarraySum(arr.data(),n);

//     return 0;
// }


#include<iostream>
using namespace std;
#include<limits.h>
int maximum(int a,int b,int c){
    if(a>=b&&a>=c){return a;}
    else if(b>=a&&b>=c){return b;}
    else{return c;}
}
int reco(int* a,int l,int h){
    if(l==h){return a[l];}
    int mid=(l+h)/2;
    int lss=reco(a,l,mid);
    int rss=reco(a,mid+1,h);
    int maxRight=INT_MIN;
    int maxLeft=INT_MIN;
    int sum=0;
    for(int i=mid;i>=l;i--){
        sum+=a[i];
        maxLeft=maximum(sum,maxLeft,INT_MIN);
    }
    sum=0;
    for(int i=mid+1;i<=h;i++){
        sum+=a[i];
        maxRight=maximum(sum,maxRight,INT_MIN);
    }
    int css=maxLeft+maxRight;
    return maximum(lss,rss,css);
}
int main(){
    int a[]={1,5,-8,9,10,-17,-17,20};
    int n=8;
    cout<<reco(a,0,n-1);
}