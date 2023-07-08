/*
    vector<int> nums(size,value);

    nums.begin()
    ->end()
    ->rbegin()
    ->rend()

    CAPACITY::
    ->size()
    ->max_size()
    ->capacity()
    ->empty()
    
    ELEMENT ACCESS::
    ->nums[i]
    ->nums.at(i)
    ->front()
    ->back()

    MODIFIERS::

    ->assign(7,100) // {100,100,100,100,100,100,100}
    ->push_back()
    ->pop_back()
    ->erase()
    ->swap()


    ->sqrt()/sqrtf()/sqrtl() -> double/float/long :: cout<<fixed<<setprecision(after_point_digit)<<sqrt(value);
    ->power(x,y)//x^y;



*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    vector<vector<int>> matrix;

    vector<int> row;
    row.push_back(1);
    row.push_back(2);
    row.push_back(3);
    matrix.push_back(row);

    nums.push_back(1);
    nums.push_back(2);
    nums.capacity();
    nums.size();
    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());
    //Iterators
    //Iterator(it) takes the first element address than it travels to next element by "it++".
    vector<int>::iterator it = row.find(3); //creating Iterator && Iterator initialisation
  //find
    nums.erase(it,it+3); // erase(start from, to end).
    return 0;
}

/*
  [] in vector use for update and get value;

*/