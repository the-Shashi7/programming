#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];

void Insert(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            hashTable[arr[i]][0] =1;
        }else{
            hashTable[abs(arr[i])][1] = 1;
        }
    }
}

void Find(int ele){
    if(ele>=0){
        if(hashTable[ele][0] == 1){
            cout<<"Element Present!"<<endl;
        }else{
            cout<<"Element not Present!"<<endl;
        }
    }else{
        if(hashTable[abs(ele)][1] == 1){
            cout<<"Element Present!"<<endl;
        }else{
            cout<<"Element not Present!"<<endl;
        }
    }
}

void NonRep(int arr[],int n){
    unordered_map<int,int> numap;
    for(int i=0;i<n;i++){
        int key = arr[i];
        numap[key]++;
    }

    for(auto x : numap){
        if(x.second == 1){
            cout<<x.first<<" ";
        }else{
            continue;
        }
    }
}

// https://practice.geeksforgeeks.org/problems/key-pair5616/1
bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    unordered_map<int,int> umap;
	    for(int i=0;i<n;i++){
	        umap[arr[i]]++;
	    }
	    for(auto itr = umap.begin(); itr!= umap.end();itr++){
	        auto key = itr->first;
	        auto val = itr->second;
	        auto pair = x - key;
	        if(pair == key){
	            if(val>1) return true;
	        }else{
	            if(umap.find(pair)!=umap.end()){
	                return true;
	            }     
	        }
	    }
	    return false;
	}
 
 //https://leetcode.com/problems/group-anagrams/submissions/
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> umap;
        
        for(auto x : strs){
            string str = x;
            sort(str.begin(),str.end());
            if(umap.find(str)!=umap.end()){
                umap[str].push_back(x);
            }else{
                umap[str].push_back(x);
            }
        }
        for(auto c : umap){
            ans.push_back(c.second);
        }
        
        return ans;
    }


int main(){
    int n = 7;
    int arr[n] = {1,-2,3,5,6,7,-10};
    Insert(arr,n);
    Find(-10);

    unordered_set<int> s;
    s.insert(10);
    s.insert(35);
    s.insert(43);
    s.insert(51);
    for(auto x:s) cout<<x<<" ";
    cout<<endl;
    cout<<s.size()<<endl;
    //s.clear(); cout<<endl;
    int key  = 10;
    if(s.find(key)!=s.end()) cout<<"Keys is Present"<<endl;
    cout<<s.size()<<endl;
    int del = 10;
    s.erase(del);
    cout<<s.size()<<endl;
    cout<<s.count(5)<<endl;

    //unordered_map<keys,value> map;

    unordered_map<string,int> umap;
    umap["Shashi"] = 26;
    umap["Ravi"] = 16;
    umap["Sandeep"] = 23;

    //for(auto x: umap) cout<<x.first<<" "<<x.second<<" , ";
    for(auto it = umap.begin();it!=umap.end();it++){
        cout<<it->first<<" "<<it->second<<",";
    }
    cout<<endl;
    cout<<umap.size()<<endl;
    string key1 = "Shashi";
    if(umap.find(key1)!=umap.end()){
        auto temp = umap.find(key1);
        cout<<"Found => "<<temp->first<<endl;
        umap.clear();
    }else{
        cout<<"Not FOUND"<<endl;
    }
    cout<<umap.size()<<endl;

    unordered_map<int,int> umaped;
    int arr1[] = {1,2,3,4,0,1,4,2,4,5,3,3,3,7,9};

    for(int i=0;i<15;i++){
        int key = arr1[i];
        umaped[key]++;
    }
    for(auto x: umaped){
        cout<<x.first<<" "<<x.second<<endl;
    }
    NonRep(arr1,15);

    return 0;
}


/*
Time complexity of search,delete,insert -> should be  O(1)
    in hashing ;

    not usefull :: 1) finding closet value
                   2) Sorted Data

    Usefull In :: 1)Dictionaries
                  2)Cryptography
                  3)caches
                  4)symbol table in compiler/interpretor
                  5)Routers

    Direct Access Table NOT works fine
        phone numbers are keys
        floating ,point numbers   because, it can't handle larges values
        keys are string

HOW HASH FUNCTION WORK?

    1.Should always map alarge key to same small key
    2.Should generate value from 0 to m-1
    3.Should be fast O(1) for itegers, and O(l) for string of lenght(l);
    4.Should uniformly distribute large key into hash table slots
    
 
Collision :: When more than one keys are pointed same position
    collision handle by : 
    1)closed hashing : Each entry of array is head of linked list which store the value of same key value;|| separate channing work as open addressing technique 

    2)Open hashing   :In open hashing we will find the alternate position for that keys
                    h(a) = hf(a)+f(i)
                    (i) Linear probility  => f(i) -> i
                    (ii)Quadractic Problty=> &(i) ->i^2
                    (iii)Double hashing   => f(i) ->i*h;(a)

M = no. of slots in hash table
N = no> of keys to be inserted

    load factor a = N/M;
if no.of slots will be high , then there is more chance of collision

Expected chain length  = we don't know , worst case: evey key is inserted in same chain

expected chain length = a;

we can implement chaining by linkedlist , vector etc


 ->unordered_set is base on hash table run in average O(1) and worst O(n) tc complexcity;
 ->set based in redblack tree run in average O(logn);

        insert();
        size();
        clear()-> all deleted;
        begin();
        end();
        find();
        erase()->umap.erasre(keys);
        count();

    Unordered_set<keys> : have only keys;
    unordered_map<keys,value> : have key and value pair;

Lambda Expression ::

    [&](int a,int b){ return expression }  // [&](parameters){ return expenssion}

    its using a lambda function durig sort. the lambda function specifices how to sort:
        1)if the two numbers have different frequencies, the one with smallr frequency 
            goes first
        2)otherwise the one that is lexicographically greater goes first;

*/ 