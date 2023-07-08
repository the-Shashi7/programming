/* #include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int w = INF, to = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

int n;
vector<vector<Edge>> adj;

void prim() {
    int total_weight = 0;
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "No MST!" << endl;
            exit(0);
        }

        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (Edge e : adj[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }

    cout <<"Total Weight :: "<< total_weight << endl;
}

int main(){
    n = 6;
    adj = {{{2,1},{1,3},{4,4}},{{2,0},{3,3},{3,2},{7,5}},{{3,1},{5,3},{8,5}},{{1,0},{3,1},{5,2},{9,4}},{{4,0},{9,3}},{{7,1},{8,2}}};
    prim();
    return 0;
} */


#include<bits/stdc++.h>
using namespace std;
/* 
int findMinVertex(int* weight,bool* visited,int n){
    int minVertex = -1;
    for (int i = 0; i < n; i++){
        if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Prims(int** edges,int n){
    int* parents = new int[n];
    int* weight = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parents[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n; i++){
        int minVertex = findMinVertex(weight,visited,n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j]<weight[j]){
                    weight[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
        
    }
   for (int i = 1; i < n; i++){
        if(parents[i]<i){
            cout<<parents[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parents[i]<<" "<<weight[i]<<endl;
        }
   } 
} */

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


int main(){
    /* int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
         edges[i][j] = 0;   
        }
    }

    for (int i = 0; i < e; i++){
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout<<endl;

    Prims(edges,n);

    for(int i = 0; i,n;i++ ){
        delete [] edges;
    }
    delete edges; */

    int n,E;
    cin>>n>>E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].source = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }
    Kruskals(edges,n,E);

    return 0;
}