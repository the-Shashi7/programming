/*
   Operations          TC          SC
1) Insertion        O(logn)      O(1)
2) Delection        O(logn)      O(1)
3) GetMin or Max    O(logn)      O(0)

*/
#include <bits/stdc++.h>
using namespace std;

class HeapTree
{
public:
    int *arr;
    int capacity;
    int size;

    HeapTree(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    };

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }

    // insert() TC:O(logn)
    void Insert(int k)
    {
        if (size == capacity)
        {
            cout << "\nOver flow :Could not insert\n";
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = k;

        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
};
// the minimum value in heap or maximum ... TC:O(1)
void getMin(int arr[],int n){ 
    cout << arr[0] << endl;
}

// Print O(n);
void Print(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MinHeapify(int arr[], int n, int i){
    for(int i=0;i<n;i++){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[largest] > arr[left]){
            largest = left;
        }
        if (right < n && arr[largest] > arr[right]){
            largest = right;
        }
        if (largest != i){
            swap(arr[largest], arr[i]);
            MinHeapify(arr, n, largest);
        }
    }
}

// remove the minimum element to maintain the heap property TC:O(logn)
void extractMin(int arr[],int size){
    if (size <= 0)
    {
        return;
    }

    swap(arr[0], arr[size - 1]);
    size--;
    MinHeapify(arr,size,0);
}

// delete() TC:O(logn)
void Delete(int arr[], int size, int i){
    swap(arr[i],arr[size-1]);
    arr[size-1] = -1;
    extractMin(arr,size);
    MinHeapify(arr,size,0);
}


// replace i th element with value k;

void DecreaseKey(int arr[], int n, int i, int k)
{
    arr[i] = k;
    MinHeapify(arr, n, 0);
}


//https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/

priority_queue<int,vector<int>,greater<int>> pq;
    int gk;
KthLargest(int k, vector<int>& nums) {
    gk = k ;
    for(int i = 0; i< nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
     }
    }
    };
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>gk){
            pq.pop();
        }
        return pq.top();
    }

int main()
{
    HeapTree ht(11);
    ht.Insert(6);
    ht.Insert(2);
    ht.Insert(5);
    ht.Insert(1);
    ht.Insert(0);
    ht.Insert(2);
    
    int arr[6] = {9,2,4,8,6,3};
    MinHeapify(arr,6,0);
    Print(arr,6);
    getMin(arr,6);
    DecreaseKey(arr,6,3,12);
    Delete(arr,6,2);
    Print(arr,6);

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


    for making min heap:
        priority_queue<int,vector<int>,greater<int>> pq (1,2,3,5,6);

    
    In priority_queue<pair<int,int>> pq;
        value is sort with key in decending order , if two keys are same then it sort according to value decending order;



*/