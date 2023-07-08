#include<bits/stdc++.h>
using namespace std;
//Next Greater Elements O(n^2);
void NGE(vector<int> v){
    vector<int> ans(v.size(),-1);
    for (int i = 0; i < v.size(); i++){
        for (int j = i+1; j < v.size(); j++){
            if(v[i]<v[j]){
                ans[i] = v[j];
                break;
            }
        }
    }
    for(auto x: ans) cout<<x<<" ";
}
//NGE_2(O(n)); 
void NGE_1(vector<int> v){
    vector<int> ans(v.size());
    stack<int> s;
    for (int i = v.size()-1; i >=0 ; i--){
        //
        while(!s.empty() && s.top() <= v[i]){
            s.pop();
        }
        s.empty() ? (ans[i] = -1):(ans[i] = s.top());
        s.push(v[i]);
    }
    for(auto x : ans) cout<<x<<" ";
}

//Next Smallest elements O(n);

void NSE_1(vector<int> v){          
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = v.size()-1; i >= 0 ; i--){   
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }
        s.empty() ? (ans[i] = n):(ans[i] = s.top()) ; 
        s.push(i);
    }
    for(auto x : ans) cout<<x<<" ";
}

//Next Smallest elements

void PSE_1(vector<int> v){          
    int n = v.size();
    vector<int> ans(n,0);
    stack<int> s;
    for(int i = 0; i < n ; i++  ){
            while(!s.empty() && v[s.top()]>=v[i]){
                s.pop();
            }
            s.empty() ? ans[i] = -1 : ans[i] = s.top();
            s.push(i);
        }
    for(auto x : ans) cout<<x<<" ";
}
//NGE_2 LeetCode 503 :: given array is circular array and find its NGE
void NGE_circular(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> s;

    for (int i = 0; i < 2*n; i++){
        int idx = i>=n ? i-n : i;
        while(!s.empty() && nums[idx] > nums[s.top()]){
            ans[s.top()] = nums[idx];
            s.pop();
        }
        if(ans[idx] == -1) { s.push(idx) ; }
    }
    for(auto x : ans) cout<<x<<" ";
}

/*GFG :: https://www.geeksforgeeks.org/the-stock-span-problem/ 
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and 
we need to calculate the span of the stock’s price for all n days. The span Si of the stock’s price on a given 
day i is defined as the maximum number of consecutive days just before the given day, for which the price of 
the stock on the current day is less than its price on the given day. */

void Stock(vector<int> stock){
    int n = stock.size();
    vector<int> ans(n);
    stack<int> s;

    for(int i=0 ; i < n ; i++){
        while(!s.empty() && stock[s.top()]<= stock[i]){
            s.pop();
        }
        s.empty()? ans[i] = i+1: ans[i] = i- s.top();
        s.push(i);
    }
    for(auto x : ans) cout<<x<<" ";
}

/*
https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/
Given an array of integers, the task is to find the maximum absolute difference between 
the nearest left and the right smaller element of every element in the array. 

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4 
*/

void Diff_LR(vector<int> v){
    int n = v.size();
    int max_diff = 0;
    vector<int> rs(n);
    vector<int> ls(n);
    stack<int> s;
    for (int i = 0; i < n; i++){
        while(!s.empty() && s.top()>=v[i]){
            s.pop();
        }
        s.empty()? ls[i] = 0 :ls[i] = s.top();
        s.push(v[i]);
    }

    while(!s.empty()) s.pop();

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()>=v[i]){
            s.pop();
        }
        s.empty()? rs[i] = 0: rs[i] = s.top();
        s.push(v[i]);
    }

    for(int i=0;i<n;i++){
        max_diff = max(max_diff,abs(rs[i]-ls[i]));
    }
    
    cout<<"Max Differenec : "<<max_diff<<endl;
}

/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/
int largestRectangleArea(vector<int>& heights) {
        int area = INT_MIN;
        int n = heights.size();
        
        if(n==0) return 0;
        if(n==1) return heights[0];
        
        vector<int> prev_smaller(n,0);
        vector<int> next_smaller(n,n);
        stack<int> s;
        
        for(int i =n-1 ; i>=0 ; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            s.empty() ? next_smaller[i] = n: next_smaller[i] = s.top(); //next greater element may at nth place;
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i = 0; i < n ; i++  ){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            s.empty() ? prev_smaller[i] = -1: prev_smaller[i] = s.top();
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            area = max(area, (next_smaller[i]-prev_smaller[i]-1)*heights[i]);
        }
        return area;
}



/* 85. Maximal Rectangle ::https://leetcode.com/problems/maximal-rectangle/
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area
*/
int maximalRectangle(vector<vector<char>>& matrix) {
        //to be done
}

/* 20. Valid Parentheses :: https://leetcode.com/problems/valid-parentheses/ */

bool isValid(string s) {
           stack<char> bracket;
    for (char& c : s) {
        switch (c) {
            case '(': bracket.push(c); break;
            case '{': bracket.push(c); break;
            case '[': bracket.push(c); break;
            case ')': if (bracket.empty() || bracket.top()!='(') return false; else bracket.pop(); break;
            case '}': if (bracket.empty() || bracket.top()!='{') return false; else bracket.pop(); break;
            case ']': if (bracket.empty() || bracket.top()!='[') return false; else bracket.pop(); break;
            default: ; 
             }
         }
    return bracket.empty() ;
}

bool isValid1(string s) {
        stack<char> st;
        for(auto i:s)  
        {
            if(i=='(' or i=='{' or i=='[') st.push(i); 
            else  
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();
            }
        }
    return st.empty(); 
}

//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

void Valid_Sub_Leng(string s){
    int count = 0;
    int n = s.length();
    stack<char> st;

    for(int i = 0;i<n;i++){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(!st.empty() && s[i]==')' && st.top() == '('){
                st.pop();
                count=count+2;
            }
        }
    }
    cout<<"Valid Subsrting is : "<<count<<endl;
}

/* 921. Minimum Add to Make Parentheses Valid :: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/

int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()=='(' && s[i] == ')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    return st.size();
}

/*
Validate Stack Sequences
https://leetcode.com/problems/validate-stack-sequences/
*/
// TC: O(n) sc:O(n)
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(auto val:pushed){
            st.push(val);
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }   
        return st.size() == 0;
}
//TC: O(n),SC:O(1);
bool validateStackSequencesO(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        int i=0;
        for(auto c:pushed){
            pushed[i++] = c;
            while(i>0 && pushed[i-1] == popped[j]){
                j++;
                i--;
            }
        }   
        return i == 0;
    }


int main(){
    vector<int> v = {2,1,5,6,2,3};
    vector<int> s = {100,80,60,70,60,75,85};
    vector<int> d = {2, 1, 8};
    string st = "((()()()()(((())";
    NGE(v);
    cout<<endl;
    NSE_1(v);
    cout<<endl;
    PSE_1(v);
    cout<<endl;
    NGE_circular(v);
    cout<<endl;
    Stock(s);
    cout<<endl;
    Diff_LR(d);
    cout<<endl;
    Valid_Sub_Leng(st);
    
    return 0;
}