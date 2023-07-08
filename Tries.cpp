/*
    Operations          TC                  SC
1) Insertion        O(lenth of word)       O(1)
2) Deletion         O(lenth of word)       O(1)
3) Searching        O(lenth of word)       O(1) 
*/
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
  public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        //base cse
        if(word.length() == 0){
            root->isTerminal = true;
            return; 
        }
        //assumption , word will in capital
        int index = word[0] - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            //absent
            child  = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode* child;
        //Prenst
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            //absent
            return false;
        }
        //recursion
        return searchUtil(child,word.substr(1));
    }
    
    bool SearchWord(string word){
        return searchUtil(root,word);
    }

    void RemoveUtil(TrieNode* root,string word){
          if(word.length()==0){
            root->isTerminal = false;
            cout<<"Removed"<<endl;
            return;
          }
          int index = word[0]-'a';
          TrieNode* child;
          if(root->children[index] != NULL){
             child = root->children[index];
          }else{
                cout<<" Word is not found"<<endl;
          }
          RemoveUtil(child,word.substr(1));

          //remove child node if it is useless
          if(child->isTerminal == NULL){
            for (int i = 0; i < 26; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
          }
    }
    void RemoveWord(string word){
        RemoveUtil(root,word);
    }

};

int main(){

    Trie *t = new Trie();
    t->insertWord("shiva");
    t->insertWord("hanumaan");
    t->insertWord("lakshman");
    t->insertWord("ram");
    t->insertWord("ravan");
    cout<<"PRESENT : "<<t->SearchWord("ram")<<endl;
    cout<<"PRESENT : "<<t->SearchWord("ravan")<<endl;
    t->RemoveWord("ravan");
    cout<<"PRESENT : "<<t->SearchWord("rava")<<endl;
    t->RemoveWord("ravan");
    
    return 0;
}

/*
Tries use for store string: are,as,the,this,same,that 
    =>maximum child of one node of tries is 26; Dark the ending charater of given word
    =>Space optimize for storing the string
    =>
    =>Type of Tries :  1) normal tries  2)compressed tries:it store word in single node if no futher node is created from it, and for more space complexsity optimize]ation 


                    start
                   /  |  \
                 a    s    t
                / \   |     \
               r   s  a      h
              /       |     /|\
             e        m    e a i
                      |      |  \
                      e      t   s
*/