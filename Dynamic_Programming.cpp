#include<bits/stdc++.h>
using namespace std;
 /*
    Methods            TC              SC
1)DP(top-down)        O(n)            O(n)+O(n)
1)DP(down-up)         O(n)            O(n)
1)OPTIMIZE            O(n)            O(1)

*/

//0-1 knapsack recursive + memorization
int static t[1002][102]; // t[n][cap] initialize with -1
int KnapSack(int wt[],int val[],int cap,int n){
    if(n==0 || cap ==0) return 0;
    if(t[n][cap]!=-1){
        return t[n][cap];
    }
    if(wt[n-1] <= cap ){
        return  t[n][cap] = max(val[n-1]+KnapSack(wt,val,cap-wt[n-1],n-1),KnapSack(wt,val,cap,n-1));
    }else if(wt[n-1]>cap){
        return t[n][cap] = KnapSack(wt,val,cap,n-1);
    }
}

//subset sum problems with recursion and DP TC : exponential
bool isSub(int arr[],int n,int sum){
    if(sum==0) return true;
    if(n==0) return false;
    if(arr[n-1]>sum)
        return isSub(arr,n-1,sum);
    return isSub(arr,n-1,sum) || isSub(arr,n-1,sum-arr[n-1]);
}

//Now adding DP  TC : O(n*sum) and SC : O(sum*n)

bool isSubDP(int arr[],int n,int sum){
    bool subset[n+1][sum+1];
    //if sum = 0 then answer is true
    subset[0][0] =true;
    for(int i=1;i<=n;i++){
        subset[i][0] = true;
    }
    //if n=0 then answer is false
    for(int i =1 ;i<=sum;i++){
        subset[0][i] = false;
    }
    //fill the subset table in bottom up manner
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(j < arr[i-1])
                subset[i][j] = subset[i-1][j];
            if(j>=arr[i-1])
                subset[i][j] = subset[i-1][j] || subset[i-1][j-arr[i-1]];
        }
    } 
    return subset[n][sum];
}

//Equal Sum Partition:: https://leetcode.com/problems/partition-equal-subset-sum/

bool canPartition(vector<int>& nums){
    int sum = 0;
    int n = nums.size();
    for(auto x: nums) sum+=x;
    if(sum%2!=0) return false;
    sum/=2;
    //isSubSet
    bool dp[n+1][sum+1];
    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
           if(j < nums[i-1]) dp[i][j] = dp[i-1][j];
           else dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
        }
    }
    return dp[n][sum];
}

//Unbounded Knapsack :: can have multiple occurence; 











//LONGEST COMMON SUBSEQUENCE ::
int LCSbyRec(string s1,string s2,int n1,int n2){
    if(n1==0||n2==0) return 0;
    if(s1[n1-1]==s2[n2-1]) 
        return 1 + LCSbyRec(s1,s2,n1-1,n2-1);
    else{
        return max(LCSbyRec(s1,s2,n1-1,n2),LCSbyRec(s1,s2,n1,n2-1));
    } 
}
//convert memorization
int d[1000][1000]; //initialize with -1;
int LCSmem(string s1,string s2,int n,int m){
    if(n==0||m==0) return 0;
    if(d[n-1][m-1]!=-1){
        return d[n-1][m-1];
    }else if(s1[n-1]==s2[m-1]){
        return d[n-1][m-1] = 1+ LCSmem(s1,s2,n-1,m-1);
    }else{
        return t[n-1][m-1] = max(LCSmem(s1,s2,n-1,m),LCSmem(s1,s2,n,m-1));
    }
}
//topdown TC: O(n**2);
int LCStopdown(string s1,string s2,int n,int m){
    int d[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                d[i][j] = 0;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                d[i][j] = 1+d[i-1][j-1];
            }else{
                d[i][j] = max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    return d[n][m];
}
//for printing longest common subsequence
string PrintSubseq(int n,int m,string s1,string s2,int **dp){
    int i=n,j=m;
    string s = "";
    while(i<0 && j<0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--,j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
}

//length of Longest common string 
int LCString(string s1,string s2,int n,int m){
    int d[n+1][m+1];
    int larg = 0;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                d[i][j] = 0;
            }else{
                if(s1[i-1] == s2[j-1]){
                    d[i][j] = 1 + d[i-1][j-1];
                    larg = max(larg,d[i][j]);
                }else{
                    d[i][j] = 0;
                }
            }
        }
    }
    return larg;
}

//Print Longest common string
string LongestCommonString(string s1, string s2,int n,int m){
    int maxlen = 0;
    int maxStr = 0;
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else{
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                    if(dp[i][j]>maxlen){
                        maxlen = dp[i][j];
                        maxStr = i;
                    }else{
                        dp[i][j] = 0 ;
                    }
                }
            }
        }
    }
    return s1.substr(maxStr-maxlen,maxlen);
}

int ShortestSuperSequence(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }else{
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return (m+n)-dp[n][m];
}
string ShortestSuperSequencePrint(string s1,string s2,int n,int m){
    //find lcs()
    int dp[n+1][m+1];
    string res = "";
    while(n>0 && m>0){
        if(s1[n-1]==s2[m-1]){
            res.push_back(s1[n-1]);
            n--,m--;
        }else{
            if(dp[n-1][m]>dp[n][m-1]){
                res.push_back(s1[n-1]);
                n--;
            }else{
                res.push_back(s2[m-1]);
                m--;
            }
        }
    }
    while(n>0){
        res.push_back(s1[n-1]);
        n--;
    }
    while(m>0){
        res.push_back(s2[m-1]);
        m--;
    }
    reverse(res.begin(),res.end());
    return res;
}
//longest palidromic subsquence or //Minimum number of deletion in a string to make it a palindrome
//https://leetcode.com/problems/longest-palindromic-subsequence/
int LCS(string s1,string s2,int n,int m){
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    dp[i][j] = 0;
                }else{
                    if(s1[i-1]==s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n = s.length();
        return LCS(s,r,n,n);
    }


//longest palidrome subsequence

/*
   Minimum Number of Insertion and Deletion to convert String a to String b

    #del = a.lenth()-lcr(a,b);
    #ins = b.lenth()-lcr(a,b);
    min = del+ins;

*/

//Matrix chain multiplication






//Fibonaci Number with the help of DP top-down
long long fibo_Helper(long n,long long *ans){
    if(n<=1) return n; // n=0=>0, n=1=>1
    if(ans[n]!= -1) return ans[n]; //Checking if output already exist or not
    
    long long a = fibo_Helper(n-1,ans); // fibonaci call for first last
    long long b = fibo_Helper(n-2,ans); // fibonaci cal for second last
    
    return ans[n] = a+b; //fibonaci of nth number    
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
/*  if there is a problems where is option whether the element choose or not there should use recursion and if
        ther is overlaping then use DP 

    Dynamic Programming: MEMORIZING THE UNIQUE RESULTS;
    
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