#include<bits/stdc++.h>
using namespace std;
typedef long long ll;  //or #define ll long long

// DFS printing Depth first search ((Defth Firts Search DFS))
void PrintDFS(int** edgesArr,int vertices,int starting_vertices,bool* visited){
    cout<<starting_vertices<<" ";
    visited[starting_vertices] = true;
    for(int i = 0; i < vertices ; i++){
        if(i==starting_vertices){
            continue;
        }//Just for safety 
        if(edgesArr[starting_vertices][i]==1){
            if(visited[i]){
                continue;
            }
            PrintDFS(edgesArr,vertices,i,visited);
        }
    }
}
 
void DFS(int** edges,int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    for (int i = 0; i < n; i++){
        if(!visited[i]){ 
            PrintDFS(edges,n,i,visited);
        }
    }  
   delete [] visited; 
}

//BFS printing of graph

void PrintBFS(int** edgesArr,int vertices,int starting_vertices,bool* visited){
      queue<int> pendingVertices; 
      pendingVertices.push(starting_vertices);
      visited[starting_vertices] = true;
      while (!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for (int i = 0; i < vertices; i++){
            if(i== currentVertex){
                continue;
            }
            if(edgesArr[currentVertex][i]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
        
    }      
}

void BFS(int** edges, int n){
    bool* visited = new bool[n];
    for (int i = 0;i < n;i++){
        visited[i] = false;
    }
    for (int  i = 0; i < n; i++){
        if(!visited[i]) 
            PrintBFS(edges,n,i,visited);
    }
    delete [] visited; 
}

//todo Get path of graph
//isconneted graph and connected vertex


//Kruskal's Algorithms help to caluculate minimum spanning tree


int main(){
    int vertices,edges;
    cout<<"Enter the Number of vertex and Edges \n";
    cin>>vertices>>edges;
    //to store the edges we create 2d array
    int** edgesArr = new int*[vertices];
    for (int i = 0; i < vertices; i++){
        edgesArr[i] = new int[vertices];
        for (int j = 0; j < vertices; j++){
         edgesArr[i][j] = 0;   
        }
    } 
    //Asking for directed or undirected graph
    bool undirected;
    cout<<"Graph is Directed-> Enter 0 or Undirected -> Enter 1\n";cin>>undirected;
    for (int i = 0; i < edges; i++){
        int firstVertices,secondVertices;
        cout<<"Enter the Edges between the Vertex-1 and Vertex-2\n";
        cin>>firstVertices>>secondVertices;
        edgesArr[firstVertices][secondVertices] = 1;
        if(undirected){
            edgesArr[secondVertices][firstVertices] = 1;
        }
    }

    cout<<"DFS : "; DFS(edgesArr,vertices);
    cout<<endl;
    cout<<"BFS : "; BFS(edgesArr,vertices);
    //TODo delete all the memory
    for (int i = 0; i < vertices; i++){
        delete [] edgesArr[i];
    }
    delete [] edgesArr; 
    
    return 0;
}
/*
//https://leetcode.com/discuss/general-discussion/655708/Graph-For-Beginners-Problems-or-Pattern-or-Sample-Solutions


Tree is a special type of Graps where all nodes are connected to ecah others
    vertices:: nodes of graphs

    Cyclic Graph : A graph containing at least one cycle is known as a Cyclic graph.

    Cycle Graph : The graph in which the graph is a cycle in itself, the degree of each vertex is 2. 

    Graph -> NULL graph(no edges),TRivial(one one vertex) directed graph ans Undirected graph
   
    -> edges   :: connected paths between two vertices
   
    -> Adjacent vertices :: if two vertices has direct edge between them are called adjacent vertices
   
    -> degree :: Number of edges going from or to the vertices
   
    -> path   :: collection of edges by which we can travel one vertice to another vertices
   
    -> connecting graph :: Direct/indirect path between all the vertices.
   
    -> connected component :: one or more vertices wich is not connected to others

    
    
    => minimum no of edges in graph = 0(if graph not connected to any of vertices)
    
    => minimum no of edges of connected graph = n-1( n is number of vertices)
    
    => minimum no of edges of complete graph = nC2 = n(n-1)/2
    (complete graph means each vertices connected to all other vertices) 


    Grap can be applied by                           adding edge       Removing     Initializing
                           1)adjacency Matrix           O(1)              O(1)          O(N*N)
                           2)adjacency list             O(1)              O(N)          O(N)



degree of undirected node/vertice  :: number of edges from that node/vertices
    total degree of graph :: 2*(num of edges)
    path :: a sequesnce of node and vertice non of node is visited twice a path

degree of directed node/vertice  :: number of edges incomming or outgoing to or from that node/vertices
    indegree :: total number of incoming edges
    outdegree:: total number of outgoing edges

    total degree of graph: (indegree + outdegree) :: 2*(num of edges)

DAG (directed acyclic graph);

SC : O(v+e) Initialize array for adj.List disadv.. TC : remove edge O(e),remove vertex O(v+e);
O(v*v) Initialize array for adj.matrix with value 0;

A ""spanning tree"" is a sub-graph of an undirected connected graph, which includes all the vertices of the graph with a minimum possible number of edges. If a vertex is missed, then it is not a spanning tree.
A minimum spanning tree is a spanning tree in which the sum of the weight of the edges is as minimum as possible.
*/