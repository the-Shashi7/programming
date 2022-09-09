#include<bits/stdc++.h>
using namespace std;
template<typename T>

//Creating Binary Tree

class Tree_Binary{
    public:
     T data;
     Tree_Binary<T>* left;
     Tree_Binary<T>* right; 

    Tree_Binary(int data){
        this->data= data;
        this->left = NULL;
        this->right = NULL;
    }
};

//Creating Printing Function

void Print_BinaryTree(Tree_Binary<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<" L - "<<root->left->data;
    }
    if(root->right){
        cout<<" R - "<<root->right->data;
    }
    cout<<endl;
    Print_BinaryTree(root->left);
    Print_BinaryTree(root->right);
}

//TakeInput Function

Tree_Binary<int>* TakeInput(){
    int root_value;
    cout<<"Enter root value "<<endl;
    cin>>root_value;
    if(root_value == -1){
        return NULL;
    }

    Tree_Binary<int>* root = new Tree_Binary<int>(root_value);
    Tree_Binary<int>* leftChild = TakeInput();
    Tree_Binary<int>* rightChild =TakeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}

//Input taking by ROWS 

Tree_Binary<int>* TakeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data : ";
    cin>>rootData;
    Tree_Binary<int>* root = new Tree_Binary<int>(rootData);

    queue<Tree_Binary<int>*> PendingNodes;
    PendingNodes.push(root);
    while (PendingNodes.size()!= 0){
        Tree_Binary<int>* front = PendingNodes.front();
        PendingNodes.pop();
        cout<<"Enter the left vale of "<<front->data<<endl;
        int leftChildData; cin>>leftChildData;
        if(leftChildData!=-1){
            Tree_Binary<int>* child = new Tree_Binary<int>(leftChildData);
            front->left = child;
            PendingNodes.push(child);
        }

        cout<<"Enter the Right value of "<<front->data<<endl;
        int rightChildData;cin>>rightChildData;
        if(rightChildData!=-1){
            Tree_Binary<int>* child = new Tree_Binary<int>(rightChildData);
            front->right = child;
            PendingNodes.push(child);
        }
    }
    return root;
}

//Number of nodes in Binary Tree

int NumNode(Tree_Binary<int>* root){
    int ans = 1;
    if(root==NULL){
        return 0;
    }
    ans+=NumNode(root->left);
    ans+=NumNode(root->right);

    return ans;

    /* ----------------OR--------------
    if(root==NULL) return 0;
    return 1+ NumNode(root->right)+NumNode(root->left);
    */
}

//Maximum value of Binary Tree

int MaxNode(Tree_Binary<int>* root){
    int sum = INT_MIN;
    if(root==NULL){
        return sum;
    }
    sum=max(root->data,max(MaxNode(root->left),MaxNode(root->right)));
    return sum;
}

//Height of Binary Tree

int Height_BTree(Tree_Binary<int>* root){
    int height = 0;
    if(root==NULL){
        return 0;
    }
    height = max(Height_BTree(root->left),Height_BTree(root->right));
    return height+1;
}

//Depth of Binary Tree

void Depth_BTree(Tree_Binary<int>* root,int level){
    if(root==NULL){
        return;
    }else if(level==0){
        cout<<root->data<<" ";
    }
    Depth_BTree(root->left,level-1);
    Depth_BTree(root->right,level-1);
}

//Sum of All node of Binary Tree

int Sum_Node(Tree_Binary<int>* root){
    int sum = 0;
    if(root==NULL){
        return 0;
    }
    sum = (root->data)+(Sum_Node(root->left) + Sum_Node(root->right));
    return sum;
}

void Preorder_Btree(Tree_Binary<int>* root){
    if(root==NULL){ return ;}
    cout<<root->data<<" ";
    Preorder_Btree(root->left);
    Preorder_Btree(root->right);
}
void Postorder_Btree(Tree_Binary<int>* root){
    if(root==NULL){ return ;}
    Postorder_Btree(root->left);
    Postorder_Btree(root->right);
    cout<<root->data<<" ";
}

void Inorder_Btree(Tree_Binary<int>* root){
    if(root==NULL){
        return;
    }
    Inorder_Btree(root->left);
    cout<<root->data<<" ";
    Inorder_Btree(root->right);
}

//Diameter of Binary Tree is the maximum height between two nodes

int Diameter_Btree(Tree_Binary<int>*root){
    if(root==NULL){ return 0;}
    int option1 = Height_BTree(root->left) + Height_BTree(root->right);
    int option2 = Diameter_Btree(root->left);
    int option3 = Diameter_Btree(root->right);

    return max(option1,max(option2,option3));
}

//Checking is BST
int Maximum(Tree_Binary<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(Maximum(root->left),Maximum(root->right)));
}

int Minimum(Tree_Binary<int>* root){
    if(root) {
        return INT_MAX;
    }
    return min(root->data,min(Minimum(root->left),Minimum(root->right)));
}

bool isBST(Tree_Binary<int>* root){
    if(root==NULL){
        return 1;
    }
    int LeftMax = Maximum(root->left);
    int RightMin = Minimum(root->right);
    bool Option = (root->data > LeftMax)&&(root->data <= RightMin) && isBST(root->left) && isBST(root->right);
    return Option;
}



int main(){
/*     Tree_Binary<int>* root = new Tree_Binary<int>(1);
    Tree_Binary<int>* right = new Tree_Binary<int>(2);
    Tree_Binary<int>* left = new Tree_Binary<int>(3);
    Tree_Binary<int>* left2 =new Tree_Binary<int>(4);
    root->left = left;
    root->right = right;
    left->left = left2; */
    Tree_Binary<int>* root =TakeInputLevelWise();
    //BT  ::1 2 3 4 5 -1 8 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    //BST :: 10 8 12 7 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
    //BST :: 
    cout<<NumNode(root)<<endl;
    Print_BinaryTree(root);
    cout<<MaxNode(root)<<endl;
    cout<<Height_BTree(root)<<endl;
    Depth_BTree(root,2);
    cout<<endl;
    cout<<Sum_Node(root)<<endl;
    Preorder_Btree(root);
    cout<<endl;
    Postorder_Btree(root);
    cout<<endl;
    Inorder_Btree(root);
    cout<<endl;
    cout<<isBST(root)<<endl;
    delete root;
    return 0;
}

/*
CBT : 2^(h-1)<= n <= 2^h -1

*/