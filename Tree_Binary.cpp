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

//                TREE TRAVERSALS

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

//Check if tree is equal

bool isSame(Tree_Binary<int>* p,Tree_Binary<int>* q){
    if(p==NULL && q == NULL) return true;
    if(p==NULL || q == NULL) return false;

    return isSame(p->left,q->left) && isSame(q->right,q->right) && p->data == q->data;
}


//                  ::LEVELWISE TRAVERSAL::

vector<int> LevelOrder(Tree_Binary<int>* root){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Tree_Binary<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()){
        Tree_Binary<int>* temp = pendingNodes.front();
        pendingNodes.pop();
        ans.push_back(temp->data);
        if(temp->left!=NULL) pendingNodes.push(temp->left);
        if(temp->right!=NULL) pendingNodes.push(temp->right);
    }
    return ans;
}

vector<vector<int>> levelOrder(Tree_Binary<int>* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Tree_Binary<int>*> pendingNodes;
        pendingNodes.push(root);
        while(1){
            int size = pendingNodes.size();
            if(size==0) return ans;
            vector<int> data;
            while(size>0){
                Tree_Binary<int>* temp = pendingNodes.front();
                data.push_back(temp->data);
                pendingNodes.pop();
                if(temp->left != NULL) pendingNodes.push(temp->left);
                if(temp->right != NULL) pendingNodes.push(temp->right);
                size--;
            }
            ans.push_back(data);
        }
        return ans;
}
// =-=-=-=-=-=-=-=-=-=-=-= zig-zag traversal  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
vector<vector<int>> ZigzagOrder(Tree_Binary<int>* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Tree_Binary<int>*> q;
    q.push(root);
    int count=0;
    while(1){
        int size = q.size();
        count++;
        vector<int> data;
        while(size>0){
            Tree_Binary<int>* temp = q.front();
            q.pop();
            data.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            size--;
        }
        if(count%2==0) reverse(data.begin(),data.end());
        ans.push_back(data);
    }
    return ans;
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
    return max(root->data, max(Maximum(root->left),Maximum(root->right)));
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
    bool Option = (root->data > LeftMax) && (root->data <= RightMin) && isBST(root->left) && isBST(root->right);
    return Option;
}
//Checking is tree a balance binary tree: the abs(heigtL - heightR)<=1;

bool isBalanceBT(Tree_Binary<int>* root){
    if(root==NULL) return true;
    return isBalanceBT(root->left) && isBalanceBT(root->right) && abs(Height_BTree(root->left)-Height_BTree(root->right))<=1;
}

//Left View of Binary tree

vector<int> leftView(Tree_Binary<int>* root){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Tree_Binary<int>*> q;
    q.push(root);
    while (1){
     int size = q.size();
     if(size==0) return ans;
     int data = -1;
     while(size>0){
        Tree_Binary<int>* temp = q.front();
        q.pop();
        data = temp->data;
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);  //For right view switch the temp->right with temp->left
        size--;
      }   
      ans.push_back(data);
    }
    return ans;
}
//LCA  3*O(n) Sc : O(n) 
bool findPath(Tree_Binary<int>* root,vector<Tree_Binary<int>*> paths,Tree_Binary<int>* p){
    if(root==NULL) return false;
    paths.push_back(root);
    if(root==p) return true;
    if(findPath(root->left,paths,p) || findPath(root->right,paths,p)) return true;

    paths.pop_back();
    return false;
}
Tree_Binary<int>* LCA(Tree_Binary<int>* root,Tree_Binary<int>*p,Tree_Binary<int>* q){
    vector<Tree_Binary<int>*> path1,path2;
    if(!findPath(root,path1,p)||!findPath(root,path2,q))
        return NULL;
    Tree_Binary<int>* ans =NULL;
    for(int i=0;i<path1.size() && path2.size();i++){
        if(path1[i]==path2[i])
            ans =path1[i];
    }
    return ans;
}
//O(n) and sc:O(h)

Tree_Binary<int> * dfsTraverseLCA(Tree_Binary<int> * root, Tree_Binary<int> * p , Tree_Binary<int> * q){
    if( root == p || root == q || root == NULL)
        return root;
    Tree_Binary<int>* left = dfsTraverseLCA(root->left, p, q);
    Tree_Binary<int>* right = dfsTraverseLCA(root->right, p, q);
    if( left && right)
        return root; 
    else
        return left ? left : right;
}


//Horizontal Height
unordered_set<int> st;
void inorder(Tree_Binary<int>* root,int s){
    if(!root){
        st.insert(s);
        inorder(root->left,s-1);
        inorder(root->right,s+1);
    }
}
int VertiWidth(Tree_Binary<int>* root){
    st.clear();
    inorder(root,0);
    return st.size();
}

//Inverted Tree :: https://leetcode.com/problems/invert-binary-tree/submissions/

Tree_Binary<int>* invertTree(Tree_Binary<int>* root) {
    queue<Tree_Binary<int>*> q;
    q.push(root);
    while(!q.empty()){
        Tree_Binary<int>* node = q.front();
        q.pop();
        if(node){
            q.push(node->left);
            q.push(node->right);
            swap(node->left,node->right);
        }
    }
    return root;
}

//recursive
Tree_Binary<int>* invertTreeRec(Tree_Binary<int>* root){
    if(root==NULL) return root; 
    invertTreeRec(root->left);
    invertTreeRec(root->right);
    swap(root->left,root->right);
    return root;
}

//Subtree of another tree ::https://leetcode.com/problems/subtree-of-another-tree/

bool isSame1(Tree_Binary<int>* a,Tree_Binary<int>* b){
    if(b==NULL && a == NULL) return true;
    if(b==NULL || a == NULL) return false;

    return isSame1(a->left,b->left) && isSame1(a->right,b->right) && a->data == b->data;
}

bool isSubtree(Tree_Binary<int>* root,Tree_Binary<int>* subRoot){
    if(!root) return false;
    else if(isSame1(root,subRoot)){
        return true;
    }else{
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    } 
}

//Construct BT wit Inorder and Preorder ::https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Tree_Binary<int>* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++; 
        Tree_Binary<int>* root = new Tree_Binary<int>(inorder[pivot]);
        root->left = build(preorder, inorder, rootIdx, left, pivot-1);
        root->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return root;
    }
    Tree_Binary<int>* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
}

//Construct by inorder and postorder

Tree_Binary<int> *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        Tree_Binary<int> *node = new Tree_Binary<int>(po[b]);
        int SI = x;  
        while(node->data != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    Tree_Binary<int>* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
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
    //BT  :: 1 2 3 4 5 -1 8 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    //BST :: 10 8 12 7 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
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
    //cout<<isBST(root)<<endl;
    vector<int> ans = leftView(root);
    for(auto x: ans){
        cout<<x<<" ";
    }
    delete root;
    return 0;
}

/*
                        "Binary Tree"
        The maximum children of Node is two, and left node should filled first
        
        In a Binary Tree with N nodes, the minimum possible height :: Log(N+1)-1;

The maximum number of node at "i"th level in BT is 2^i;
The maximum nunber of node of Height "h" tree : 2^h-1;

Full Binary Tree :: A Bt is full binary tree if every node has 0 or 2 children;

Complete BT :: A Bt is complete Tree if all the leveles are completely filled except possibly 
                the last level and the last level has all keys left as possible;

    Complete Binary Tree : 2^(h-1) <= node <= 2^h -1

Perfetc BT :: A binary tree is a perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at same level

Balance Binary Tree : A binary tree is Blanced Binary tree if height of tree is O(loh n) where n is
                        the number of nodes


AVL tree   :: AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes

Red_ Black :: A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the color (red or black). 
              These colors are used to ensure that the tree remains balanced during insertions and deletions. Although the balance of the tree is not perfect, it is good 
              enough to reduce the searching time and maintain it around O(log n) time
            
        Rules That Every Red-Black Tree Follows: 
            
            =>Every node has a color either red or black.
            =>The root of the tree is always black.
            =>There are no two adjacent red nodes (A red node cannot have a red parent or red child).
            =>Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
            =>All leaf nodes are black nodes.


Degenerate Binary Tree ::  A tree where every internal nodes has one child such trees are 
                           Such trees are performance wise sam as linked list. 


            Traversal In BT

            1
          /   \
        2       3
      /  \    
     4    5

    Level Transv   :: 12345
    Inorder Tranv  :: 42513
    Preorder Tranv :: 12453
    Postorder Tranv:: 45231

if any preorder and Postorder tranversal are same that means trees are equal;
*/