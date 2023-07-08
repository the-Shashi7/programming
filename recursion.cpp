#include<bits/stdc++.h>
using namespace std;

void BinarSearch(int arr[],int start,int end,int key){
    if(start > end){
        cout<<"Not Found in Binary Search"<<endl;
        return;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==key){
        cout<<"Found in Binary Search : "<<(mid+1)<<endl;
        return;
    } 
    if(arr[mid]<key){
        BinarSearch(arr,mid+1,end,key);
    }
    else{
        BinarSearch(arr,start,mid-1,key);
    }
}

void LinearSearch(int arr[],int start,int size , int key){
    if(size == 0){
        cout<<"Not Found in Linear"<<endl;
        return;
    };
    if(arr[start]==key){
        cout<<"Found in linear Search : "<<start+1<<endl;
    }
    else{
        start++;
        LinearSearch(arr,start,size-1,key);
    }
}

void ReverseString(string &str,int i,int j){
    if(i>j){
        return;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    ReverseString(str,i,j);
}
bool Palidrome(string str,int s,int e){
    if(s>e){
        return true;
    }
    if(str[s]!=str[e]){
        return false;
    }else{
        return Palidrome(str,s+1,e-1);
    }
}

int Power(int x,int y){
    if(y==0 && x == 0){
        return 0;
    }
    if(y==0){
        return 1;
    }
    if(y==1){
        return x;
    }
    int ans = Power(x,y/2);
    if(y%2==0){
        return ans*ans;
    }
    else{
        return x*ans*ans;
    }
}

void BubbleSort(int *arr,int size){
    if(size==0||size==1){
        return;
    }
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    BubbleSort(arr,size-1);
}

void SelectionSort(int *arr,int size){
    if(size==0||size==1){
        return;
    }
    int mini= arr[0],j = 0;
    for (int i = 0; i < size-1; i++){
        if(arr[i]<mini){
            mini=arr[i];
            j=i;
        }
    }
    swap(arr[j],arr[0]);
    SelectionSort(arr+1,size-1);
}
/*TODO recursion insertion Sort*/
void InsertionSort(int *arr,int size){
    if(size==0||size==1){
        return;
    }
    for(int i=0;i<size-1;i++){
        if(arr[0]>arr[1]){
            swap(arr[0],arr[1]);
        }
    }
    InsertionSort(arr-1,size-1);
}
/*TODO Merge in recursion*/
void Merge(int *arr1, int s,int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++){
        first[i] = arr1[k++];
    }
     k = mid+1;
    for (int i = 0; i < len2; i++){
        second[i] = arr1[k++];
    }

    int index1 = 0;
    int index2 = 0;
    int mainArrayIndex = s;

    while (index1 < len1 && index2<len2 ){
        if(first[index1]<second[index2]){
            arr1[mainArrayIndex++] = first[index1++];
        }else{
            arr1[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1){
        arr1[mainArrayIndex++] = first[index1++];
    }
    while (index2<len2){
        arr1[mainArrayIndex++] = second[index2++];
    }
    delete []first;
    delete []second;    
}

void MergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    MergeSort(arr,mid+1,e);
    MergeSort(arr,s,mid);
    Merge(arr,s,e);

}

int Partision(int *arr,int s,int e){
    int pivot = arr[s];
    int count = 0;
    for (int i = s; i <= e; i++){
        if(pivot>arr[i]){
            count++;
        }
    }
    return s+count;
}

void QuickSort(int *arr,int s,int e){
    if(s>=e){
        return;
    } 
    int mid = Partision(arr,s,e);
    swap(arr[s],arr[mid]);
    QuickSort(arr,s,mid-1);
    QuickSort(arr,mid+1,e);
}

//------------------------LeetCode PowerSet;

void solve(vector<int> &nums , vector<int> &output, int index,vector<vector<int>> &ans){
    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums,output,index+1,ans);
    //Include
    output.push_back(nums[index]);
    solve(nums,output,index+1,ans);
}
vector<vector<int>>subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums,output,index,ans);
    return ans;
}



int main(){
    
    vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);

    subsets(set);
    return 0;
}

/*
recursion : a function call itself.


*/