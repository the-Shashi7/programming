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
        
        while(!s.empty() && s.top() <= v[i]){
            s.pop();
        }
        s.empty() ? (ans[i] = -1):(ans[i] = s.top()) ; 
        s.push(v[i]);
    }
    for(auto x : ans) cout<<x<<" ";
}
void NSE_1(vector<int> v){
    vector<int> ans(v.size());
    stack<int> s;

    for (int i = 0; i < v.size() ; i++){
        
        while(!s.empty() && s.top() <= v[i]){
            s.pop();
        }
        s.empty() ? (ans[i] = -1):(ans[i] = s.top()) ; 
        s.push(v[i]);
    }
    for(auto x : ans) cout<<x<<" ";
}
//NGE_2 LeetCode 503 :: given array is circular array and find its NGE
void NGE_circular(vector<int> v){

}

int main(){
    vector<int> v = {9,2,3,4,4,6,2};
    NGE(v);
    cout<<endl;
    NGE_1(v);
    cout<<endl;
    NSE_1(v);
    
    return 0;
}