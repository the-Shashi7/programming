#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {12,2,3,4,5};
    int (*ptr3)[5] = &arr; 
    cout<<ptr3<<endl;  // address of entire array
    cout<<*ptr3<<endl; // addrees of first element of array
    cout<<**ptr3<<endl;// value of first element
    int *ptr ;  
    int *ptr2;
    ptr=arr;           // arr[i] = *(arr+1);
    ptr = (int*)(&arr+1);//&arr or arr show address of first element of array and 
    cout<<&arr+1<<endl;  //(&a+1) address of the element after the last element of array a;
    cout<<&arr+2<<endl;
    cout<<ptr<<endl;

    int *arrofptr[5]; //array of pointers size 5;
    int a=10,b=20,c=30,d=40,e=50;
    arrofptr[0]=&a;
    arrofptr[0]=&b;
    arrofptr[0]=&c;
    arrofptr[0]=&d;
    arrofptr[0]=&e;

    int arr2d[4][4];
    int x=1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr2d[i][j] = (i+1)*(10) + (j+1);
        }
    }
    cout<<sizeof(arr2d)/sizeof(int)<<endl;
    cout<<arr2d<<endl; //  "arr2d": first row address and "arr2d+1" : 2nd row address 
    cout<<*(*(arr2d)+6)<<endl; // " *(arr2d)+1" first row firt column and *(arr2d)+3" first row firt fourth
    cout<<arr2d<<endl;
    cout<<**(arr2d+1)<<endl;

//dynamic memory allocation is done by "new" keyword;

    int *p = new int[5]; //a pointer to an array of 5 integers
    int *q= new int(6) ; //a pointer to an integer

    int num=10;
    int &ref = num;
    int &&num=8;
    cout<<ref<<"  "<<num<<endl;
    return 0;
}
/*
What is Segmentation Error ?
– It is the runtime error caused because of the memory access violation. For Eg :-Stackoverflow, read violation etc..
We often face this problem when working out with pointers in c++/c.
In this example we will see how to find the segmentation error in the program. We will find which lines causes the 
segmentation fault error.

*/

//arr is an integer pointer (int*) which points the first element of the array.
//&arr is an integer array pointer (int*)[5] which points the whole array.