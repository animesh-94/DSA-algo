#include<bits/stdc++.h>
using namespace std;

vector<int> par[200100];
int dep[200100];

//Preprocessing the the chains
void dfs(int node, int parent, int depth, vector<vector<int>> &tree){
    dep[node] = depth;
    
    //if i=0 then 2^i => 2^0 == 1 ie the immediate parent
    par[node].resize(20, 0);
    par[node][0] = parent;
    
    for(int i=1; i<20; i++){
        //recurrence relation from Binary lifting 
        //we have already set the ....A->B values while traversing the dfs 
        //{ next(x, i);
        //{ next(next(x, i-1), i-1)
        if(par[node][i-1] != 0) {
            par[node][i] = par[par[node][i-1]][i-1];
        } else {
            par[node][i] = 0;
        }
    }
    
    for(auto neigh: tree[node]){
        if(neigh!=parent){
            dfs(neigh, node, depth+1, tree);
        }
    }
}

//quering part
int lca(int u, int v){
    if(dep[u] < dep[v]){
        swap(u, v);
    }
    
    for(int i=19; i>=0; i--){
        if((dep[u]-dep[v])&(1<<i)){
            u=par[u][i];
        }
    }
    
    //if they are in the same subtree like u->v
    if(u==v){
        return u;
    }
    
    //if they are in seperate subtree
    for(int i=19; i>=0; i--){
        if(par[v][i] != par[u][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    
    return par[u][0];
}

int main(){
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> tree(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, 0, 0, tree);
    while(q--){
        int u, v;
        cin >> u >> v;
        
        cout << lca(u, v) << endl;
    }
    
    return 0;
}
