#include<bits/stdc++.h>
using namespace std;

class LinkedList {
    public :
        int data;
        LinkedList* next;

    LinkedList(int data){
        this->data = data;
        this->next = NULL;
    }
};

LinkedList* TakeInput(){
    cout<<"Enter Node Data (to end -1)"<<endl;
    int data;
    cin>>data;
    LinkedList* head = NULL;
    LinkedList* tail = NULL;

    while(data!=-1){
        LinkedList* newNode = new LinkedList(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

LinkedList* Insert(LinkedList* head,int i,int data){ // inser list at i th position
    LinkedList*newNode = new LinkedList(data);
    int count = 0;
    LinkedList *temp = head;
    if(i==0){
        newNode->next = head;
        //head = newNode;
        return newNode;
    }
    while (temp != NULL && count < i-1){
        temp = temp ->next;
        count++;
    }
    if(temp != NULL){
        LinkedList *a =temp->next;
       // newNode->next = temp->next;
        temp->next = newNode;
        newNode ->next =a;
    }
    return head;
}

void Delete(LinkedList* head,int Data){
    if(head->data == Data){
        head = head->next;
    }
    while(head){
        head= head->next;
        if(head->data==Data){
            head = head->next;
        }
    }
}

//remove dublicate
LinkedList* delDublicate(LinkedList* head){
    if(head==NULL || head->next ==NULL) return head;
    LinkedList* newNode = delDublicate(head->next);
    if(head->data == newNode->data) return newNode;
    else{
        head->next = newNode;
        return head;
    }
}
//iterative
LinkedList* delDublicateItr(LinkedList* head){
    if(head==NULL||head->next ==NULL) return head;
    while (head->next!=NULL){
        if(head->data == head->next->data){
            LinkedList* del = head->next;
            head->next = del->next;
            delete del;
        }else{
            head = head->next;
        }
    }
    return head;
}

//Check Cycle in LinkedList
bool cycleDectection(LinkedList* head){
    LinkedList *slow = head,*fast = head;
    while(fast!=NULL||fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}


//Palidrome linked list 1) reverse the list and comapare it if not equal return false
        //2) slow ptr start from middle and one ptr start from head comapre and if not equal return false
LinkedList* reverse(LinkedList *head){
    LinkedList* temp = head;
    LinkedList* prev = NULL;
    LinkedList* curr = NULL;
    while(temp!=NULL){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}

bool isPalidrome(LinkedList* head){
    LinkedList* prev = head;
    LinkedList* rev = reverse(head);

    while(prev!=NULL && rev!=NULL){
        if(prev->data != rev->data){
            return false;
        }
        prev = prev->next;
        rev = rev->next; 
    }
    return true;
}

class DoublLinked {
    public:
        int data;
        DoublLinked *prev = NULL;
        DoublLinked *next = NULL;
};

//Design Browser in ll
    list<string> history;
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        auto del  = it;
        del++;
        history.erase(del,history.end());
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it!=history.begin() && steps--){
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(it!= --history.end() && steps--){
            it++;
        }
        return *it;
    }

void Print(LinkedList* head){
    LinkedList* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

int main(){
    LinkedList* head = TakeInput();
    //Insert(head,0,100);
    //Delete(head,5);
    Print(head);
    return 0;
}

/*linked list uses as implement of stack and queues
Image gallery 
music player 
browser history
HashMap and HashSet 

Array : has random traversal possible but not in linkedList

shallow copy :: copy of 

*/