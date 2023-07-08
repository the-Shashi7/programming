#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>a,pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
}

int main(){
    vector<pair<int,int>> p;
    for(int i=0;i<5;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }

    for(auto x : p){
        cout<<x.first<<" -> "<<x.second<<endl;
    }

    return 0;
} 