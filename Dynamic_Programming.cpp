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
//N stairCase







//<=======================================================================================================>
int main(){
    cout<<fibo(50)<<endl;
    cout<<fibo_tab(50)<<endl;
    cout<<fibo_Optim(50)<<endl;
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