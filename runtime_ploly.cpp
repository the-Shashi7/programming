// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Base {
    public:
        virtual void Func(){
            cout<<"I'm from Base Class"<<endl;
        }
};
class Drive : public Base {
    public:
        void Func(){
            cout<<"I;m from Drive Class"<<endl;
        }
};

int main() {
    cout << "Hello world!"<<endl;
    Base* b1 = new Drive();
    b1->Func();
    return 0;
}