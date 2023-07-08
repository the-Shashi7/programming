#include <bits/stdc++.h>
using namespace std;
//undirected graph
void AddEdge(vector<int> *AdjList, int v1, int v2)
{
    AdjList[v1].push_back(v2);
    AdjList[v2].push_back(v1);
}

void PrintGraph(vector<int> *AdjList, int nv)
{
    for (int v = 0; v < nv; v++)
    {
        cout << v << " -> ";
        for (int j = 0; j < AdjList[v].size(); j++)
        {                                   // for(auto j : AdjList[v]){
            cout << AdjList[v][j] << " , "; // cout<<j<<" , "; }
        }
        cout << endl;
    }
}
//============================Grap with set================================================
// Adding and Searching edge O(logV)


class Graph{
    public: 
        unordered_map<int,list<pair<int,int>>> adjList;
        
        void addEdge(int u,int v,int weight){
            pair<int,int> p = make_pair(v,weight);
            adjList[u].push_back(p);
        }
        void printAdj(){
            for(auto i:adjList){
                cout<<i.first<<" -> ";
                for(auto j : i.second){
                    cout<<" ("<<j.first<<","<<j.second<<"),";
                }cout<<endl;
            }
        }
};

class Graph{
public:
    int nv;
    set<int> *AdjList; // unordered_set<int>* AdjList;
};

Graph *CreateGraph(int nv)
{
    Graph *graph = new Graph;    
    graph->nv = nv;
    // Create an array of sets represting 2) Adjancency list . size of array will be vertex;
    graph->AdjList = new set<int>[nv]; // graph->AdjList = new unoredred_set<int>[nv];
    return graph;
}

void AddEdgeSet(Graph *graph, int v1, int v2)
{
    graph->AdjList[v1].insert(v2); // Add an edge from vertex1 to vertex2
    // graph->AdjList[v2].insert(v1);  //Since graph is undirected vertex2 to vetex1
}

void PrintGraphSet(Graph *graph)
{
    for (int i = 0; i < graph->nv; i++)
    {
        set<int> lst = graph->AdjList[i]; // unordered_set<int>* lst = graph-<AdjList[i];
        cout << i << " -> ";
        for (auto itr = lst.begin(); itr != lst.end(); itr++)
        {
            cout << *itr << " , ";
        }
        cout << endl;  
    }
}
 
void SearchEdgeSet(Graph *graph, int v1, int v2)
{
    auto itr = graph->AdjList[v1].find(v2);
    if (itr == graph->AdjList[v1].end())
        cout << "Edge From " << v1 << " to " << v2 << " is not found" << endl;
    else
        cout << "Edge From " << v1 << " to " << v2 << " is found" << endl;
}

void TransposGraph(Graph *graph, Graph *Transpose, int nv)
{
    for (int i = 0; i < nv; i++)
    {
        set<int> ltr = graph->AdjList[i];
        for (auto itr = ltr.begin(); itr != ltr.end(); itr++)
        {
            AddEdgeSet(Transpose, *itr, i);
        }
    }
}
//===================unoredr_set or hashmap======================
// Searching and adding edge O(1);

//========================vector<int,list<int>> adj==============
class GraphList{
public:
    int nv;
    vector<list<int>> AdjList;

    GraphList(int nv)
    {
        this->nv = nv;
        this->AdjList.resize(nv);
    }
};

void AddEdgeList(GraphList *graph, int v1, int v2)
{
    graph->AdjList[v1].push_back(v2);
    graph->AdjList[v2].push_back(v1);
}
// BFS -> Shortes path,Min spanning tree for unwighted,cycle detection,gps,social media
vector<int> PrintBFS(GraphList *graph)
{
    vector<int> bfs_traversal;
    vector<bool> visited(graph->nv, false);
    for (int i = 0; i < graph->nv; i++)
    {
        if (!visited[i])
        {
            queue<int> pendeingVertex;
            visited[i] = true;
            pendeingVertex.push(i);

            while (!pendeingVertex.empty())
            {
                int currentVertex = pendeingVertex.front();
                pendeingVertex.pop();
                bfs_traversal.push_back(currentVertex);
                for (auto itr : graph->AdjList[currentVertex])
                {
                    if (!visited[itr])
                    {
                        visited[itr] = true;
                        pendeingVertex.push(itr);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}
// DFS -> path finding cycle detetion, topological sort,finding strong connected components

void DFS(GraphList *graph, vector<bool> &visited, vector<int> &ans, int sv){
    visited[sv] = true;
    ans.push_back(sv);
    for (auto i : graph->AdjList[sv]){
        if (!visited[i]){
            DFS(graph, visited, ans, i);
        }
    }
}

vector<int> PrintDFS(GraphList *graph){
    vector<bool> visited(graph->nv, false);
    vector<int> ans;
    for (int i = 0; i < graph->nv; i++){
        if (!visited[i])
            DFS(graph, visited, ans, i);
    }
    return ans;
}
//============================================================================================================================================================
//============================================================================================================================================================
// cycle detection Directed
bool cycle(int sv, vector<bool> &visited, vector<bool> &currVisited, vector<int> adj[]){
    visited[sv] = true;
    currVisited[sv] = true;

    for (auto vertex : adj[sv])
    {
        if (!visited[vertex])
        {
            if (cycle(vertex, visited, currVisited, adj))
                return true;
        }
        else if (visited[vertex] == true && currVisited[vertex] == true)
        {
            return true;
        }
    }
    currVisited[sv] = false;
    return false;
}

bool isCyclic(vector<int> adj[], int v){
    vector<bool> visited(v, false), currVisited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (cycle(i, visited, currVisited, adj))
                return true;
        }
    }
    return false;
}
// detect Cycle in undirected graph
bool cycleUndirect(int sv, vector<int> adj[], vector<bool> visited, int parent)
{
    visited[sv] = true;
    for (auto v : adj[sv])
    {
        if (!visited[v])
        {
            if (cycleUndirect(v, adj, visited, sv))
                return true;
        }
        else if (v != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCyclicUndirected(vector<int> adj[], int v)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (cycleUndirect(i, adj, visited, -1))
                return true;
        }
    }
    return false;
}

//=============================================Paths==================================================================
void dfs(vector<vector<int>> &graph, vector<int> &currPath, vector<vector<int>> &res, int sv)
{
    currPath.push_back(sv);
    if (sv == graph.size() - 1)
    {
        res.push_back(currPath);
    }
    else{
        for (auto vertex : graph[sv])
        {
            dfs(graph, currPath, res, vertex);
        }
    }
    currPath.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> res;
    vector<int> currPath;
    dfs(graph, currPath, res, 0);
    return res;
}
//Shortest Path in Undirected Graphs(BFS)

vector<int> shortestPath(vector<pair<int,int>> edges,int source,int dest){
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v); 
        adjList[v].push_back(u);
    }
    //do bfs
    unordered_map<int, bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()){
        int front = q.front();
        q.pop();
        for(auto v : adjList[front]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = front;
                q.push(v);
            }
        }
    }
    //prepare shortest path
    vector<int> ans;
    int currNode = dest;
    ans.push_back(currNode);

    while (currNode!=source){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;  
}

//Shortest Path in Directed Acyclic Graphs
vector<int> ans;
void dfsDAG(int sv,unordered_map<int,vector<pair<int,int>>>&adjList,vector<int>&ans,vector<bool> &visit){
    visit[sv] =true;
    for(auto v : adjList[sv]){
        if(!visit[v.first]){
            dfsDAG(v.first,adjList,ans,visit);
        }
    }
    ans.push_back(sv);
}

void topologi(int V,unordered_map<int,vector<pair<int,int>>>&adjList){
    vector<bool> visit(V,false);
    for(int i=0;i<V;i++){
        if(!visit[i]){
            dfsDAG(i,adjList,ans,visit);
        }
    }
    reverse(ans.begin(),ans.end());
}
vector<int> shortestDAG(int v,unordered_map<int,vector<pair<int,int>>>&adjList,int src,int dest){
    vector<int> dist(v,INT_MAX);
    dist[src] = 0;
    for(int i=0;i<v;i++){
        for(auto x: adjList[ans[i]]){
            if(x.second <= dist[i]){
                dist[i] = x.second;
            }
        }
    }
}



//======================Judge in Town indegree/outdegree=============================================
int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> data(n + 1, 0);
    for (auto v : trust)
    {
        data[v[0]]--; // outdegree
        data[v[1]]++; // indegree
    }
    for (int i = 1; i <= n; i++)
    {
        int x = data[i];
        if (x == n - 1)
            return i;
    }
    return -1;
}

//===========================leetcode-200============
//=======leetcode-733 Flood Fill=============

bool isValid(vector<vector<int>> &image, int i, int j, int row, int col, int scolor)
{
    if (i < row && j < col && j >= 0 && i >= 0 && image[i][j] == scolor)
    {
        return true;
    }
    return false;
}
void colorgrid(vector<vector<int>> &image, int i, int j, int row, int col, int scolor, int color)
{
    image[i][j] = color;
    if (isValid(image, i + 1, j, row, col, scolor))
        colorgrid(image, i + 1, j, row, col, scolor, color);
    if (isValid(image, i - 1, j, row, col, scolor))
        colorgrid(image, i - 1, j, row, col, scolor, color);
    if (isValid(image, i, j + 1, row, col, scolor))
        colorgrid(image, i, j + 1, row, col, scolor, color);
    if (isValid(image, i, j - 1, row, col, scolor))
        colorgrid(image, i, j - 1, row, col, scolor, color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int row = image.size();
    int col = image[0].size();
    int scolor = image[sr][sc];

    if (scolor == color)
    {
        return image;
    }

    colorgrid(image, sr, sc, row, col, scolor, color);

    return image;
}
//==========Topological Sort (Kahn's BFS base Algorithms)================
vector<int> topoloSort(int V, vector<int> adj[]){
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++){
        for (auto x : adj[i]){
            indegree[x]++;
        }
    }

    for (int i = 0; i < V; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (auto v : adj[u]){
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return ans;
}

// topological by DFS
void DFSrec(int sv, vector<int> &ans, vector<bool> &visited, vector<int> adj[]){
    visited[sv] = true;
    for (auto v : adj[sv]){
        if (!visited[v]){
            DFSrec(v, ans, visited, adj);
        }
    }
    ans.push_back(sv);
}

vector<int> topoloSort(int V, vector<int> adj[]){
    vector<bool> visited(V, false);
    vector<int> ans;//we can use stack there for ans
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            DFSrec(i, ans, visited, adj);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//Multi Source BFS :: https://www.youtube.com/watch?v=xvi8PqRrAyU&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=15
//MINIMUM SPANNING TREE(MST) and PRISM ALGO
// find the minm edge which connect the current MST to remaining vertex

//Dijkstra Algorithm :: https://www.youtube.com/watch?v=dVUR3Rm6biE&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=11
//Single Source shortes path to every node from src node

vector<int> dijkdtra(int v,vector<vector<int>> adj[],int src){
    vector<int> cost(v,0);
    cost[src] = 0;
    vector<bool> visited(v,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //priority_queue<pair<minimum distance,node>>pq  increasing order
    pq.push({0,src});

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        int currCost = p.first;
        int currNode = p.second;
        pq.pop();

        if(!visited[currNode]){
            visited[currNode] = true;
            cost[currNode] = currCost;

            for(auto v : adj[currNode]){
                int neighbourNode = v[0];
                int weight = v[1];

                if(!visited[neighbourNode]){
                    pq.push({currCost+weight,neighbourNode});
                }
            }
            
        }

    }
    return cost;
}

//Prims Algorithms -> Minimum spanning tree(MST)
int spanningTree(int v,vector<vector<int>> adj[]){
    int minCost = 0;
    vector<int> costs(v,INT_MAX);
    costs[0] = 0;
    vector<bool> visited(v,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0}); // {cost,node}

    while (!pq.empty()){
        pair<int,int> p = pq.top();
        int currNode = p.second;
        int currCost = p.first;
        pq.pop();

        if(!visited[currNode]){
            visited[currNode] = true;
            minCost+=currCost;
            costs[currNode] = currCost;

            for(auto v : adj[currNode]){
                int neighbourNode = v[0];
                int neighbourCost = v[1];
                if(!visited[neighbourNode]){
                    pq.push({neighbourCost,neighbourNode});
                }
            }
        }
    }
    return minCost;
}

// kruskal's Algorithms :: Minimum cost spanning tree
class Edge { 
    public:
        int source;
        int dest;
        int weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}
void Kruskals(vector<Edge> &edges,int n,int E){
    int cost = 0;
    vector<Edge> results;
    vector<int> parents;
    
    for(auto i : parents) parents[i] = i;

    sort(edges.begin(),edges.begin()+E,compare);

    for(Edge e: edges){
        if(parents[e.source]!= parents[e.dest]){
            cost+=e.weight;
            results.push_back(e);

            int old_id = parents[e.source],new_id = parents[e.dest];
            for(int i = 0; i < n;i++ ){
                if(parents[i]==old_id){
                    parents[i] = new_id;
                }
            }
        }
    }
    cout<<"Cost"<<cost<<endl;
}




//Bellman Ford Algorithm -> useful when dijkstra fails(weight<0)
//if the graph weight is 0 or 1 then we use 0-1 algorithms
const int N = 1e5+10,INF = 10000000;
vector<pair<int,int>> G[N];
vector<int> lev(N,INF);
int n,m;

int bfs(){
    deque<int> q;
    q.push_back(1);
    lev[1] = 0;

    while (!q.empty()){
        int cur_v = q.front();
        q.pop_front();

        for (auto child : G[cur_v]){
            int child_v = child.first;
            int child_wt = child.second;
            if(lev[cur_v]+child_wt < lev[child_v]){
                lev[child_v] = lev[cur_v]+child_wt;
                if(child_wt == 1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }

        }
        
    }
    return lev[n]==INF ? -1:lev[n];
}

//DSU (Disjoint Set union) -> use in making of sets
/*
make -> Add new node to network
find -> Give parent of that element
union ->Combined two group in single 
*/
int parent[N];
int size[N];

void Make(int v){
    parent[v] = v;
}
//Finding parent of v node
int Find(int v){
    if(v==parent[v]) return v;
    //path compression
    return parent[v] = Find(parent[v]);
}
//conneted two node a and b;
void Union(int a,int b){
    a = Find(a);
    b = Find(b);
    if(a!=b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a]+=size[b];
    }
}


int main()
{

    // creating AdjMatrix;
    /* int nv,ne;
    int AdjMatrix[nv][nv];
    for (int v = 0; v < nv; v++){
        int v1,v2;
        cin>>v1>>v2;
        AdjMatrix[v1][v2]=1;
        AdjMatrix[v2][v1]=1;
    } */

    // Creating AdjList;
    /* int nv = 5;
    vector<int> AdjList[nv];
    AddEdge(AdjList,0,1);
    AddEdge(AdjList,0,4);
    AddEdge(AdjList,1,2);
    AddEdge(AdjList,1,3);
    AddEdge(AdjList,1,4);
    AddEdge(AdjList,2,3);
    AddEdge(AdjList,3,4);
    PrintGraph(AdjList,nv); */

    //=================================== Creating by SET ==============================
    /* int nv= 5;
    Graph* AdjList = CreateGraph(nv);
    Graph* Tranpose = CreateGraph(nv);
    AddEdgeSet(AdjList,0,1);
    AddEdgeSet(AdjList,0,4);
    AddEdgeSet(AdjList,1,2);
    AddEdgeSet(AdjList,1,3);
    AddEdgeSet(AdjList,1,4);
    AddEdgeSet(AdjList,2,3);
    AddEdgeSet(AdjList,3,4);

    PrintGraphSet(AdjList);
    SearchEdgeSet(AdjList,2,0);
    SearchEdgeSet(AdjList,0,4);
    TransposGraph(AdjList,Tranpose,nv);
    PrintGraphSet(Tranpose); */

    //===============================Creating by Vector========
    int nv = 5;
    GraphList *AdjList = new GraphList(nv);
    AddEdgeList(AdjList, 0, 1);
    AddEdgeList(AdjList, 1, 2);
    AddEdgeList(AdjList, 2, 0);
    AddEdgeList(AdjList, 3, 4);

    cout << "BFS : ";
    for (auto i : PrintBFS(AdjList))
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "DFS : ";
    for (auto j : PrintDFS(AdjList))
    {
        cout << j << " ";
    }

    int V = 3;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[0].push_back(2);
    cout << endl;
    // cout<<isCyclic(adj,V);
    cout << isCyclicUndirected(adj, V);

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

Dense graph is a graph in which the number of edges is close to the maximal number of edges. 
Sparse graph is a graph in which the number of edges is close to the minimal number of edges.

*/