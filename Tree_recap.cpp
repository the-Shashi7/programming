#include<bits/stdc++.h>
using namespace std;
template<typename T>

//Creating Tree Node
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;

    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
        for (int i = 0; i < children.size(); i++){
          delete children[i];   
        }
    }
};

//Printing Functions

void printTree(TreeNode<int>* root){
    //base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    //calculation
    for (int i = 0; i < root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    //recursion
    for (int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }  
}

//Taking input in level Wise

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0){   
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for (int i = 0; i < numChild; i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child =new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    return root;
}

//taking input in tree wise

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n ;
    cout<<"Enter number of children of "<<rootData<<endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

//Counting number of nodes in Tree

int numNodes(TreeNode<int>* root){
    if(root==NULL){ return 0;}
    int ans = 0;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans+1;
}
//Height Of tree
int heightTree(TreeNode<int>* root){
    if(root==NULL) return 0;
    int height = 0; 
    for (int i = 0; i < root->children.size(); i++){
        int height_subTree = heightTree(root->children[i]);
        height = max(height,height_subTree);
    }
   return height+1;
}
// Maximum node value
int Max_Node(TreeNode<int>*root){
    int max_value= INT_MIN;
    for (int i = 0; i < root->children.size(); i++){
        max_value = max(max_value,Max_Node(root->children[i]));
    }
    return max(max_value,root->data);
}
//Pre order DFS
void PreOrderDFS(TreeNode<int>*root){
    if(root==NULL){ return;}
    cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++){
        PreOrderDFS(root->children[i]);
    }
}
//Post order DFS
void PostOrderDFS(TreeNode<int>*root){
    if(root==NULL) return ;
    for(int i=0;i<root->children.size();i++){
        PostOrderDFS(root->children[i]);
    }
    cout<<root->data<<" ";
}
//depth of tree
void Depth_Node(TreeNode<int>*root,int level){
    if(root==NULL) {
        return;
    }else if(level == 0){
        cout<<root->data<<" ";
    }
    for (int i = 0; i < root->children.size(); i++){
        Depth_Node(root->children[i],level-1);
    }
}
//Lowest Common Ancestor(LCA) from bottom firts common node or parent node of that two nodes;O(n)
 


void Delete_Node(TreeNode<int>*root){
    for (int i = 0; i < root->children.size(); i++){
        Delete_Node(root->children[i]);
    }
    delete root;
}

int main(){
/*     TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    //Connecting with root
    root->children.push_back(node1);
    root->children.push_back(node2); */

    TreeNode<int>* root =takeInputLevelWise();
    // 1 3 2 3 4 0 2 5 6 0 1 7 0 0
    printTree(root);
    cout<<numNodes(root)<<endl;    
    cout<<heightTree(root)<<endl;    
    cout<<Max_Node(root)<<endl;
    PreOrderDFS(root);
    cout<<endl; 
    PostOrderDFS(root); 
    cout<<endl;
    Depth_Node(root,2);
    Delete_Node(root);

    return 0;
}