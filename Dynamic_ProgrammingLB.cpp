/*
    Method                  TC                  SC
1)  DP
2)  TABULAR
3)  OPTIMISATION

*/

#include<bits/stdc++.h>
using namespace std;
//DP top-down approach
int fibo(int n,vector<long long> dp){
    //Base case
    if(n==0||n==1) return n;
    //Check the value of n is present or not
    if(dp[n]!=-1) return dp[n];
    //Not present then push the nth fibonacci number
    dp[n] = fibo(n-1, dp)+fibo(n-2, dp);
    //return dp[n]
    return dp[n];
}
//tabular bottom-up 

int fibo_tab(int n,vector<long long> dp){
    dp[0] = 0;
    dp[1] = 1;
    //Base case
    if(n==0||n==1) return dp[n];
    
    if(dp[n]!=-1) return dp[n];

    dp[n] = dp[n-1]+dp[n-2];
    
    return dp[n];
}

int main(){

    int n;cin>>n;
    vector<long long> dp(n+1);
    for (int i = 0; i < n+1; i++) dp[i] = -1;
    cout<<fibo(n,dp)<<endl;
    return 0;
}