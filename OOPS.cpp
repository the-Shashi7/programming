#include<bits/stdc++.h>
using namespace std;

class Hero {
    private:
        int salary;
    public: // access modifier are three type 1) private which is defalt, 2)public, 3)protected
        string name;
        int power;
        char level;
        //once we make constructor the defalt contructor will vanished
        Hero(string name,int power,char level,int salary){
            this->name = name;
            this->level = level;
            this->power = power;
            this->salary = salary;
        }
        //copy contructor its do shallow copy means it copy adress previous data
        Hero(Hero &temp){
            this->name = temp.name;
            this->level = temp.level;
            this->power = temp.power;
            this->salary = temp.salary;
        }
        //for deep copy contructor for name
       /*  Hero(Hero &temp){
             string nam = temp.name;
             this->name = nam;
        } */
        //for access the private data member we have to use setter or getter
        int getSalary(){ //getter use to get the private data
            return this->salary;
        }
        int setSalary(int salary){ //setter use set the private data
            return this->salary = salary;
        }

        void Print(){
            cout<<this->name<<" "<<this->salary<<" "<<this->level<<endl;
        }
        //once we make defalt constructor the default one will vanished
        ~Hero(){
            cout<<"Destructor call";
        }
};

class Parent{
    public:
        string lastName;
        string color;
        int age;
        int height;
        Parent(){
            
        }

        Parent(string name,string color,int age,int height){
            this->lastName = name;
            this->color = color;
            this->age = age;
            this->height = height;
        }
};

class child : public Parent{
        public:
            string name;
            child(string n){
                this->name = n;
            }
            
        void sleep(){
            cout<<"child is sleeping"<<endl;
        }
};



int main(){

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

   //inherit from parent  ;; private element cannot inherit 


     
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

Ambiguity :
    

*/