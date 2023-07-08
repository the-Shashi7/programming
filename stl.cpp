#include<bits/stdc++.h>
using namespace std;

/*
map store keys as accending order;
*/


int main(){
    map<int,string> m;
    m[1] ="abc";
    m.insert({2,"cde"});

    auto itr = m.find(1); //.find function gives itrator
    cout<<(*itr).first<<" "<<(*itr).second<<endl;
    return 0;
}
