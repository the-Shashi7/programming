#include<bits/stdc++.h>
using namespace std;
template<typename v>

//Creating HashTable/HashMaps/Hashing
class MapNode{
    public:
        string key;
        v value;
        MapNode* next;

        MapNode(string key,v value){
            this->key =key;
            this->value = value;
            next = NULL;
        }
        ~MapNode(){
            delete next;
        }
        
template<typename v>
class ourMap{
    MapNode<v>* buckets;
    int count;
    int numBuckets;

  public:
    ourMap(){
        size =;
        numBuckets = 5;
        buckets = new MapNode<v>* [numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;
        }
    }
    ~ourMap(){
        for (int i = 0; i < numsBuckets; i++){
            delete buckets[i];    
        }
        delete [ buckets];
    }
}

int size(){
    return count;
}

private:
int getButcketIndex(string key){
    int hashCode = 0;
    int currentCoeff = 1;
    for (int i = key.length()-1; i >= 0; i--){
        hashCode += key[i]*currentCoeff;
        hashCode - hashCode % numBuckets;
        currentCoeff *= 37; //take 37 as prime number 
        currentCoeff = currentCoef % numBuckets;
    }  
    return hashCode % numsBuckets;    
}

public:
void insert(string key,v value){
    int bucketIndex = getBucketIndex(string key);
    MapNode<v>* head = buckets[bucketIndex];
    while (head!=NULL){
        if(head->key == key){
            head->value = value;
            return;
        }
        head = head->next;
    }
    head = buckets[bucketIndex];
    MapNode<v>*node = new MapNode<v>(key,value);
    node->next = head;
    buckets[bucketIndex] = node;
    count++;
}

v getValue(string key){
    int bucketIndex = getBucketIndex(string key);
    MapNode<v>* head = buckets[bucketIndex];
    while (head!=NULL){
        if(head->key==key){
            return head->value;
        }
        head = head->next;
    }
    return 0;
}

v remove(string key){
    int bucketIndex = getBucketIndex(string key);
    MapNode<v>* head = buckets[bucketIndex];
    MapNode<v>* prev = NULL;
    while (head!= NULL){
        if(head->key == key){
            if(prev==NULL){
                buckets[bucketIndex] = head->next;
            }else{
                prev->next = head->next;
            }
            v value =  head->value;
            head->next = NULL;
            delete head;
            count--;
            return value;
        }
        prev = head;
        head = head->next;
    }
   return 0;  
}

};
//remove dublicate from array
vector<int> removeDuplicate(int *arr,int size){
    vector<int> output;
    unordered_map<int ,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(){
    unordered_map<string,int> ourMap;
    //insert unordermap store value in internally in pair form
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"] = 2;
    ourMap["def1"] = 3;
    ourMap["def2"] = 4;
    ourMap["def3"] = 5;

    //find or Access the element
    ourMap["abc"]; //if "abc" not present then it will insert default value and return it;
    ourMap.at("abc"); //if "abc" not present then it will gives error;

    //check Presence "in map one key come only one time"
    if(ourMap.count("ghi")>0); // "count" is bool function which compare the given element in map and if element is present then is give 1 else 0;
    //size
    ourMap.size();
    //Erase
    ourMap.erase("ghi");
    //Iterator(it) takes the first element address than it travels to next element by "it++".
    unordered_map<string,int> ::iterator it; //creating Iterator 
    it = ourMap.begin();                     //Iterator initialisation
    while (it!=ourMap.end()){
        cout<<"KEY : "<<it->first<<" Values : "<<it->second<<endl; // if key are same then .at(key) return last value of key.
        it++;
    }

    //find by itrator
    unordered_map<string,int>::iterator it2 = ourMap.find("abc");
    ourMap.erase(it2);
    

    // Array for check
    int arr[5] = {1,2,2,3,5};
    vector<int> output = removeDuplicate(arr,5);
    for (int i = 0; i < output.size(); i++){
        cout<<output[i]<<" ";
    }

    return 0;
}

/*
->Collision :: When more than one keys are pointed same position
    collision handle by : 
    1)closed hashing : Each entry of array is head of linked list which store the value of same key value;|| separate channing work as open addressing technique 

    2)Open hashing   :In open hashing we will find the alternate position for that keys
                    h;(a) = hf(a)+f(i)
                    (i) Linear probility  => f(i) -> i
                    (ii)Quadractic Problty=> &(i) ->i^2
                    (iii)Double hashing   => f(i) ->i*h;(a)

                    
                Bucket array ::=>
                    _______________________________
                    |       |       |       |      |                                                       
                    |_______|_______|_______|______|
                    

->Bucket Array :: array store hash data by key
                ->each index of bucket array has head of linked list for closed hashing or seprate channing

->
->
->
->
->

*/