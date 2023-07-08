#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    int salary;

public: // access modifier are three type 1) private which is defalt, 2)public, 3)protected
    string name;
    int power;
    char level;
    // once we make constructor the defalt contructor will vanished
    Hero(string name, int power, char level, int salary)
    {
        this->name = name;
        this->level = level;
        this->power = power;
        this->salary = salary;
    }
    // copy contructor its do shallow copy means it copy adress previous data
    Hero(Hero &temp)
    {
        this->name = temp.name;
        this->level = temp.level;
        this->power = temp.power;
        this->salary = temp.salary;
    }
    // for deep copy contructor for name
    /*  Hero(Hero &temp){
          string nam = temp.name;
          this->name = nam;
     } */
    // for access the private data member we have to use setter or getter
    int getSalary()
    { // getter use to get the private data
        return this->salary;
    }
    int setSalary(int salary)
    { // setter use set the private data
        return this->salary = salary;
    }

    void Print()
    {
        cout << this->name << " " << this->salary << " " << this->level << endl;
    }
    // once we make constructor the default one will vanished
    ~Hero()
    {
        cout << "Destructor call";
    }
};

class Parent
{
public:
    string lastName;
    string color;
    int age;
    int height;
    Parent(){}
    Parent(string name, string color, int age, int height)
    {
        this->lastName = name;
        this->color = color;
        this->age = age;
        this->height = height;
    }
};

class child : public Parent
{
public:
    string name;
    child(string n)
    {
        this->name = n;
    }

    void sleep()
    {
        cout << "child is sleeping" << endl;
    }
};
// virtual function
class Base {
    public:
        virtual void Func(){
            cout<<"I'm from Base Class"<<endl;
        }
};
class Drive : public Base {
    public:
        void Func(){
            cout<<"I'm from Drive Class"<<endl;
        }
};

//Operator overloading;
class Demo{
    int n;
    int m;
    public:
        void setData(){
            cout<<"Eneter Data\n";
            cin>>n>>m;
        }
        void getData(){
            cout<<n<<" "<<m<<endl;
        }
        //doing operator overload;
        Demo operator+(Demo &obj){
            Demo temp;
            temp.n = n * obj.n;
            temp.m = m + obj.m;
            return temp;
        }
        void operator++(){
            n=n+1;
        }
        void operator++(int){
            n=n+1;
        }
};

int main()
{

    /* Hero * ravan = new Hero("Shashi",100,'A',100000);
    cout<<(ravan->getSalary())<<endl;
    ravan->setSalary(200000);
    cout<<(ravan->getSalary())<<endl;
    ravan->Print();
    delete ravan

    Hero ram("Ram",108,'A',100000);
    ram.name = "Shashi";
    ram.Print();
    Hero sita(ram);
    sita.Print();
    */

    // inherit from parent  ;; private element cannot inherit
    Base* l1 = new Drive();
    Base* l2 = new Drive();
    Base* Bases[2] = {l1,l2};
    for(int i=0;i<2;i++){
        Bases[i]->Func();
    }

    Demo a,b,c;
    a.setData();
    b.setData();
    c=a+b;
    ++a;
    a++;
    a.getData();
    c.getData();

    return 0;
}

/*
 default copy contructor do shallow copy;

 inheritance : the properties inherit from parent
    refer :: https://www.simplilearn.com/tutorials/cpp-tutorial/types-of-inheritance-in-cpp
    types of inheritance ::
        *Single :
        *Multilevel
        *Multiple
        *Hybrid
        *Heirachical

Ambiguity : same name of function present in more than one class and inherit it in child class;
    by using scope resulator(::)
    class A{
        public:
            void Say(){
                cout<<"Hello from A";
            }
    }

    class B{
        public:
            void Say(){
                cout<<"Hello from B";
            }
    }

    class C : public A, public B{

    }

    int main(){
        C obj;
        obj.A::Say()  //for accessing say from parent A;
        obj.B::Say()
    }


==============================================================
Polymorphism :-> different behavior in different situations. This is called polymorphism.
    Compile-time Polymorphism(statice ).
            function overloading :: When there are multiple functions with the same name
                                    but different parameters, then the functions are said to be overloaded

class Geeks {
public:

    // Function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " <<
                 x << endl;
    }

    // Function with same name but
    // 1 double parameter
    void func(double x)
    {
        cout << "value of x is " <<
                 x << endl;
    }

    // Function with same name and
    // 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " <<
                 x << ", " << y << endl;
    }
};

            
            
            
================== operator overloading ==============
C++ has the ability to provide the operators with 
a special meaning for a data type, this ability is known as operator overloading

    class B{
        public: 
            int a,b;
            int add(int a,int b){
                return a+b;
            }
            void operator+ (B &obj){
                int val1 = this->a;
                int val2 = obj.a;
                cout<<"Output : "<<val2-val1<<endl;
            }
    };
    int main(){
        B obj1,obj2;
        obj1.a = 4;
        obj2.a = 7;
        obj1+obj2;  //7-4 = 3
    }



====== Runtime Polymorphism.(dynamic) =============
(virtual function) : is a fuction which defined in Base and redefined in drive class and it give the ability to do runtime polymorphism     -> method overriding
refer : https://www.softwaretestinghelp.com/runtime-polymorphism-in-cpp/
 
 class Animal {
    public:
        void Speak(){    //virtual void Speak(){}
            cout<<"Speaking "<<ednl;
        }
 }
 class Dog : public Animal{
    public:
        void Speak(){
            cout<<"Barking"<<endl;
        }
 }
int main(){
    Animal A;
    Dog D;
    A.Speak(); // Speaking ,if virtual is added in Base class Speak() then it will output as Barking (drive class output)
    D.Speak(); // Barking , if function Speak() not present in Dog class then it'll inherit it from parent class Animal 
}


https://www.geeksforgeeks.org/difference-between-virtual-function-and-pure-virtual-function-in-c/

*/