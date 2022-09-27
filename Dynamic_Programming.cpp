 /*
    Methods            TC              SC
1)DP(top-down)        O(n)            O(n)+O(n)
1)DP(down-up)         O(n)            O(n)
1)OPTIMIZE            O(n)            O(1)

*/
#include<bits/stdc++.h>
using namespace std;

//Fibonaci Number with the help of DP top-down
long long fibo_Helper(long n,long long *ans){
    if(n<=1) return n; // n=0=>0, n=1=>1
    if(ans[n]!= -1) return ans[n]; //Checking if output already exist or not
    long long a = fibo_Helper(n-1,ans); // fibonaci call for first last
    long long b = fibo_Helper(n-2,ans); // fibonaci cal for second last
    ans[n] = a+b; //fibonaci of nth number
    return ans[n];
}

long long fibo(long long n){
    long long *ans = new long long[n+1];
    for (int i = 0; i <= n; i++) ans[i] = -1;
    return fibo_Helper(n,ans);
}

//DP (bottom-up) tabular
long long fibo_tab(long long n){
    long long *ans_tab = new long long[n+1];
    ans_tab[0] = 0;
    ans_tab[1] = 1;
    for (int i = 2; i < n+1; i++) ans_tab[i] = ans_tab[i-1]+ans_tab[i-2];
    return ans_tab[n];
}

//Optimization or Brain Strom code
long long fibo_Optim(long long n){
    long long prev2 = 0;
    long long prev1 = 1;
    for (int i = 0; i < n; i++){
        long long temp = prev1 + prev2;
        prev2 = prev1;
        prev1 = temp;
    }
    return prev2;
}
//<=======================================================================================================>
//N stairCase ::: https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
//1) Approch by recursion TC = O(2^N) sc = O(N)

int help(vector<int> &c ,int start){
    if(start >= c.size()) return 0;
    int opt1 = help(c,start+1); 
    int opt2 = help(c,start+2);
    return  c[start] + min(opt1,opt2);
}
int minCostStair(vector<int> &cost){
    return min(help(cost,0),help(cost,1));
}

//2) Approch Top down (recurnsion + memoization) TC : O(N) SC : O(N)+(N)
int help1(vector<int>&c,vector<int> &dp,int start){
    if(dp[start]!=-1) return dp[start];
    dp[start] = c[start] + min(help1(c,dp,start+1),help1(c,dp,start+2));
    return dp[start];
}

int minCostStair1(vector<int>&cost){
    int n = cost.size();
    vector<int> dp(n+1,-1);

    return min(help1(cost,dp,0),help1(cost,dp,1));
}
//3) Approch Bottom Down(tabular) TC : O(N) SC : (N)
int minCostStair2(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2;i<n;i++){
        dp[i] = cost[i]+ min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
//4) Approch Bottom Down (space optimization) TC : O(N) SC : O(1)
int minCostStair3(vector<int>& cost){
    int n =cost.size();
    int prev1 = cost[0];
    int prev2 = cost[1];

    for(int i=2;i<n;i++){
        int curr = cost[i] + min(prev1,prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return min(prev1,prev2);
}

//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//1) Approch by recursion TC = O(2^N) sc = O(N)
//2) Approch Top down (recurnsion + memoization) TC : O(N) SC : O(N)+(N)
//3) Approch Bottom Down(tabular) TC : O(N) SC : (N)
//4) Approch Bottom Down (space optimization) TC : O(N) SC : O(1)
//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//1) Approch by recursion TC = O(2^N) sc = O(N)
int maxNonAdjSolver(vector<int>&num,int n){
    if(n<0) return 0;
    if(n==0) return num[0];

    int inc = num[n] + maxNonAdjSolver(num,n-2);
    int exc = 0 + maxNonAdjSolver(num,n-1);

    return max(inc,exc);
}

int maxNonAdj(vector<int>& num){
    int n = num.size()-1;
    return maxNonAdjSolver(num,n);
} 

//2) Approch Top down (recurnsion + memoization) TC : O(N) SC : O(N)+(N)
int maxNonAdjSolver2(vector<int>& num,int n,vector<int>&dp){
    if(n<0) return 0;
    if(n==0) return num[0];
    if(dp[n]!=-1) return dp[n];

    int inc = num[n] + maxNonAdjSolver2(num,n-2,dp);
    int exc = 0 + maxNonAdjSolver2(num,n-1,dp);

    return dp[n] = max(inc,exc);
}
int maxNonAdj2(vector<int>&num){
    int n = num.size()-1;
    vector<int> dp(n+1,-1);
    return maxNonAdjSolver2(num,n,dp);
}
//3) Approch Bottom Down(tabular) TC : O(N) SC : (N)

int maxNonAdj3(vector<int>&num){
    int n = num.size();
    vector<int> dp(n+1);
    dp[0] = num[0];
    for(int i = 1; i< n ; i++){
        int inc = num[i] + dp[i-2];
        int exc = 0 + dp[i-1];
        dp[i] = max(inc,exc);
    }
    return dp[n-1];
}

//4) Approch Bottom Down (space optimization) TC : O(N) SC : O(1)

int maxNonAdj4(vector<int>&num){
    int n = num.size();
    int prev2 = 0;
    int prev1 = num[0];
    for(int i=1;i<n;i++){
        int inc = num[i] + prev2;
        int exc = prev1 + 0;

        int ans = max(inc,exc);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

//rober house :: https://leetcode.com/problems/house-robber/

//<=======================================================================================================>
int main(){
    cout<<fibo(50)<<endl;
    cout<<fibo_tab(50)<<endl;
    cout<<fibo_Optim(0)<<endl;
    return 0;
} 
/*
    Dynamic Programming:MEMORIZING THE UNIQUE RESULTS ;
    
                steps:: check if ans already exist 
                        yes-> return;
                        No ->
                            calculate->save for future->return;
            
                        TOP-DOWN  -> RECURSION + MEMORIZATION
                        
                        BOTTOM UP -> TABULATION
                            steps: 1) DP array created
                                   2) Check Base case
                                   3) recursive call convert in form of DP
*/