/*
    Operations      peek         insert         delete

1)LinkedList        O(1)          O(n)             O(1)
2)Binary Heap       O(1)          O(logn)          O(logn)
3)BinarySearchTree  O(1)          O(logn)          O(logn)
*/


#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
private:
    vector<int> pq;
public:
    bool isEmpty(){
        return pq.size()==0;
    }
    void getSize(){
        cout<<pq.size()<<endl;
    }
    void getMin(){
        if(!isEmpty()){
            cout<<pq[0]<<endl;
        }else{
            return;
        }
    }
    void Insert(int val){
        pq.push_back(val);
        int childIndex = pq.size()-1;

        while (childIndex > 0){
    
            int parentIndex = (childIndex-1)/2;

            if(pq[childIndex]<pq[parentIndex]){
                swap(pq[childIndex],pq[parentIndex]);
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin(){
        if(isEmpty()) return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        //down-heapify

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;

        while (leftChildIndex <pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex]> pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }if(rightChildIndex < pq.size() && pq[rightChildIndex]<pq[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;
        }
        return ans;
    }
    void Print(){
        for (int i = 0; i < pq.size(); i++){
         cout<<pq[i]<<" ";   
        }cout<<endl;
        return;
    }

    void HeapSort(){

    }
};

void KsortedArray(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i =0; i<k; i++){
        pq.push(arr[i]);
    }

    int j = 0;
    for (int i = k; i < n; i++){
        arr[i] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while (!pq.empty()){
        arr[j] = pq.top();
        pq.pop();
    }
}



int main(){
    PriorityQueue pq;
    pq.Insert(2);
    pq.Insert(4);
    pq.Insert(5);
    pq.Insert(6);
    pq.Insert(9);
    pq.Insert(8);
    pq.Print();
    pq.getMin();
    pq.getSize();
    pq.isEmpty();
    pq.removeMin();
    pq.Print();

    return 0;
}

/*
#include<queue>

priority_queue<int> pq; //default  is max-heap
pq.push(16);
pq.push(1);
pq.push(9);
pq.push(23);

pq.size() ;    //4
pq.top();      //23
pq.isEmpty();  //0

------------>converting inbuilt 

    priority_queue<int,vector<int>, greater<int>> pq;

*/