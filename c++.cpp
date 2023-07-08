#include <bits/stdc++.h>
using namespace std;
#define x 5 - 2 // Macros will not evaluate it just replace;

class Student
{
public:
    int *id;
    string name;
    string salary;
    Student()
    {   id = nullptr;
        name="None";
        salary = "0";
        cout<<"Default contructor called\n";
    }
    Student(int *id, string name, string salary)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
        cout << "Three arg constructor called\n";
    }
    //copy constructor : shallow copy
/*     Student(const Student &source){
        id = source.id;
        name = source.name;
        salary =source.salary;
        cout<<"Shallow Copy : "<<source.name<<endl;
    } */
    //Deep copy :: for the pointer value we have to create dyanamically;
    Student(const Student &source){
        id = new int;
        *id = *(source.id);
        name = source.name;
        salary = source.salary;
        cout<<"Deep Copy Call Constructor : "<<source.name<<endl;
    }

    //Move Constructor :: To not move the value
    Student(Student &&source){
        id = source.id;
        name = source.name;
        salary =source.salary;
        source.id = nullptr;
        cout<<"Move Constructor is Called"<<endl; 
    }
   
    void Print()
    {
        cout <<*id<<" , name :" << name << " , salary : " << salary << endl;
    }

    ~Student()
    {
        cout << "Destructor called\n";
    }
};

//const 
class Player1{
    string name;
    int power;
    public:
        Player1(string n,int p){
            name=n;
            power=p;
        }
        string get_name()const {
            return name;
        }
};

void Get_Name(const Player1 &p){
    cout<<p.get_name()<<endl;
}


class Player{
    private:
        string name;
        int health;
        int power;
        
        void Print(){
            cout<<name<<" "<<health<<" "<<power<<endl;
        }
};

class Test{
    public:
        static int num;
    public:
        Test(){
            cout<<"Constructor call\n";
        }
        static void Print(){
            cout<<"This calling from static"<<endl;
        }
        ~Test(){
            cout<<"Destructor call\n";
        }
};

class Time{
    int h,m;
    public:
        void getData(){
            cout<<"Enter Hour and minute\n";
            cin>>h>>m;
        }
        void putData(){
            cout<<"Hours = "<<h<<" Minutes = "<<m<<endl;
        }
        void Sum(Time t1,Time t2){
            h = (t1.m+t2.m)/60;
            h = h+(t1.h + t2.h);
            m = (t1.m+t2.m)%60;
        }
};


int main()
{
    /* int i;
    i= x*x*x; // i.e i = 5-2*5-2*5-2
    cout<<i<<endl; // 27
    int n=65;
    char m = 'A';
    cout<<int(m)<<endl;
    switch(n){
        case 64 : cout<<"64\n" ; break; // case: value cannot be variable if it is then varable should be const
        case 'A' : cout<<"A\n"; break;
        default : cout<<"Default\n"; //if default is missing then this will not give error
    }
    cout<<"Value of pointer : \n";
    int *p[10]; // array of integer pointers
    int (*q)[10]; //pointer to an array of integers
    int r[10]; //array of integers

    Student s1(1,"Shashi","1890000");
    s1.Print();
    int num=10;
    int num2 = 12;

    int *ptr = &num;
    cout<<ptr<<endl;
    ptr = &num2;
    cout<<ptr<<endl;
    cout<<(*ptr)<<endl;
    cout<<&num<<endl; */
    /* int *n = new int;
    *n=10;
    Student s1(n,"Shashi","200000");
    Student s2(s1);
    *(s2.id) = 20;
    s1.Print();
    s2.Print(); */
    
    Test T1;
    Test::Print(); // T1.Print(); this is not good way  

    Time t1,t2,t3;
    t1.getData();
    t2.getData();
    t1.putData();
    t2.putData();
    t3.Sum(t1,t2);
    t3.putData();
    return 0;
}

/*
arthematic precedence :: "*" > "/" > "%" > "+" > "-"

int n = printf("hello") //then n=4;
    switch(printf("hiii")){
        case 1:printf("Hee"); break;
        case 2:printf("Hede");break;
        case 3:printf("Hees");break;
        case 4:printf("Hedse");break;   //this will executed and output will be "helloHedse"
        default: printf("this is default");
    }
    int k=30;
    printf("%d %d %d", k<=30,k=40,k==30); //solution start from right to left
                    // 0 40 1

    ASCII value of A is 65 and a is 97
*/