#include<bits/stdc++.h>
using namespace std;
//lecture-3/4
void PrintN(int n){
    if(n==0){ 
        return;  //base case
    }
    PrintN(n-1); //Hypothesis
    cout<<n<<" "; //Induction
}
//lecture 5 Height of Tree
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data){
            this->data = data;
        }
};
int Height(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int left = Height(root->left);
    int right = Height(root->right);
    return 1 + max(left,right);
}

//Print Subsets of string
void solver(string ip,vector<string> &opv, string op){
    if(ip.length()==0){
        opv.push_back(op);
        return;
    }
    solver(ip.substr(1),opv,op+ip[0]);
    solver(ip.substr(1),opv,op);
}
//Letter case permuatation

void letter_solver(string ip,vector<string> &ans,string op){
    if(ip.length()==0){
        ans.push_back(op);
        return;
    }
    if(isdigit(ip[0])){
        letter_solver(ip.substr(1),ans,op+ip[0]);
    }else{
        letter_solver(ip.substr(1),ans,op + (char)tolower(ip[0]));
        letter_solver(ip.substr(1),ans,op + (char)toupper(ip[0]));
    }
}
//Generate all balanced Paranthesis;
void Par_Solver(vector<string> &ans,string op,int len,int left,int right){
    if(len==left){
        ans.push_back(op);
        return;
    }
    Par_Solver(ans,op+'(',len,left+1,right);
    if(left<right){
        Par_Solver(ans,op+')',len,left,right+1);
    }
}

int main(){
    PrintN(6);
    cout<<endl;
    string str = "shashi Bhushan";
    cout<<str.substr(1);
    return 0;
}