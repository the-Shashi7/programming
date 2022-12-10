/*
 Iterators:
    str.begin()   -> starting from 0
    str.end()     -> str.length
    str.rbegin()  -> 
    str.rend()    ->

 CAPACITY:
    str.size() = str.length()
    str.max_size() -> return maximum size string can reach
    str.capacity()
    str.clear()
    str.empty() bool function if length is 0 return true

 Elemet Access:str ="Hello",str2 = "Writing",str3="print 10 and then 5 more";
    str[0]//H
    str.at(0)//H
    str.back()
    str.front()

Modifiers:

    operater+=   str+=h
    append
        str.append(str2);                       // "Writing "
        str.append(str3,6,3);                   // "10 "
        str.append("dots are cool",5);          // "dots "
        str.append("here: ");                   // "here: "
        str.append(10u,'.');                    // ".........."
        str.append(str3.begin()+8,str3.end());  // " and then 5 more"
        str.append<int>(5,0x2E);                // "....."
        str.substr(from,till numbers of character);
    push_back(element)
    pop_back()
    erase(intital,final/number of element)
    str1.swap(Str2)

    str.find(Element)
    ->find_last_of()
    ->find_first_of()
    ->find_last_of()
    
    x1.compare(x2);

    isalpnum(value) // return true if value is alphabet or number.else return fasle; 
    isupper(value)  // return true for UPPERCASE ALPHABETS ,else return fasle;
    toupper(value)  // return "VALUE" ;
    tolower(value)  //
    strlwr()/strupr("CompuTer ScienCe PoRTAl fOr geeKS") // return "COMPUTER SCIENCE PORTAL FOR GEEKS"
    stoi("2223") return string -> integer;



*/

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
    char str1[100] = "Hello Shashi";
    char str2[100] = "GoodNight";

    strcat(str1,str2);//Hello Shashi GoodNight
    strcmp(str1,str2);//-1 for false and 0 for true
    strcpy(str1,str2);//strcpy(to,from) i.e str1 = GoodNight
    strlen(str1);//12

    /*-------------------------*/

    string numArrray[5] ={"One","Two","Three","Four","Five"};
    char strArray[5][6] ={"One","Two","Three","Four","Five"};
    cout<<strArray[0]<<endl;//One or strArray[0][2]->e

    /*-----------------------------------*/

    vector<string> vectString;
    vectString.push_back("One");
    vectString.push_back("Two");
    vectString.push_back("Three");
    vectString.push_back("Four");
    cout<<vectString[0][2]<<endl;
    return 0;
}