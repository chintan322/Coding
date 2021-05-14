// Maximum Sum Subarray Array

#include <iostream>
#include <math.h>
#include <climits>
using namespace std;


int main(){    
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];    
    }
    
    // Kadane's algorithm
    int currSum=0;
    int maxSum=INT_MIN;

    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum<0) currSum=0;
        maxSum=max(maxSum,currSum);
    }
    
    cout<<maxSum<<endl;


    // Cumulative sum approach
    // int currSum[n+1];
    // currSum[0]=0;

    // for(int i=1;i<=n;i++){
    //     currSum[i]=currSum[i-1] + arr[i-1];
    // }

    // int maxSum = INT_MIN;
    // for(int i=1;i<=n;i++){
    //     int sum=0;
    //     for(int j=0;j<i;j++){
    //         sum = currSum[i]-currSum[j];
    //         maxSum = max(sum,maxSum);
    //     }
    // }
    // cout<<maxSum<<endl;


    // Bruteforce
    // int ans = INT_MIN;
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int curr=0;
    //         for(int k=i;k<=j;k++){
    //             curr += arr[k];
    //         }
    //         ans = max(ans,curr);
    //     }
    // }
    // cout<<ans<<endl;



    return 0;

}