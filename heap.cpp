/*
   Operations          TC          SC
1) Insertion        O(logn)      O(1)
2) Delection        O(logn)      O(1)
3) GetMin or Max    O(logn)      O(0)

*/
#include<bits/stdc++.h>
using namespace std;

class HeapTree{
    public:
        int *arr;
        int capacity;
        int size;
    
    HeapTree(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    };

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

//insert() TC:O(logn)
    void Insert(int k){
        if(size==capacity){
            cout<<"\nOver flow :Could not insert\n";
            return;
        }
        size++;
        int i = size-1;
        arr[i] = k;

        while (i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
        
    }

//the minimum value in heap or maximum ... TC:O(1)
    void getMax(){
        cout<<arr[0]<<endl;
    }
//remove the minimum element to maintain the heap property TC:O(logn)
    int extractMin(){
        if(size<=0){
            return INT_MAX;
        }
        if(size==1){
            size--;
            return arr[0];    
        }

        int root = arr[0];
        arr[0] = arr[size-1];
        size--;

    }
//delete() TC:O(logn)
    void Delete(int i){
       swap(arr[i],arr[size-1]);
       size--;
       while (i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
            }

    }
//Print O(n);
    void Print(){
        for (int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};


int main(){
    HeapTree ht(11);
    ht.Insert(6);
    ht.Insert(2);
    ht.Insert(5);
    ht.Insert(1);
    ht.Insert(0);
    ht.Insert(2);
    ht.Insert(3);
    ht.Print();
    ht.getMax();
    ht.Delete(0);
    ht.getMax();
    ht.Print();
    return 0;
}

/*
->Heap data structure:use in heap sort
->Implemtation in (priority queue)
        Heap :=> max-heap and min-heap

->Binary Heap :=> It is complete binary tree(Binary tree which completed filled except last level and last level should be filled from left to right); 
                        1
                       /  \
                      3    6
                     / \    \           it not complete BT
                    5   9    1
                    
                         1
                       /  \
                      3    6             It is complete BT;
                     / \  /              leftNode(i)   = 2i+1
                    5   98               rightNode(i)  = 2i+2
                                         parentNode(i) = abs(i-1)/2
-> Application of heaps
    1)Heap sort tc:O(nlogn);
    2)PriorityQueue in TC:O(logn)
    3)In Graph Algo 



-> STL of heap
        vector<int> v1 = {1,2,3,4,5}
    make_heap(v1.begin(),v1.end()) now v1.front is 5;
    v1.push_back(8); make_heap(v1.begin(),v1.end()); v1.front is 8;
    push_heap()
    pop_heap()
    sort_heap(v1.begin(),v1.end()) // 1,2,3,4,5,8
    is_heap(v1.begin(),v1.end()) // true if it is else false
    is_heap_until(v1.begin(),v1.end()) //It will itrate till array is heap

*/