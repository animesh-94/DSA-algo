#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int depth, int val, vector<int> &dep, vector<int> &pref, vector<vector<int>> &par, vector<vector<pair<int, int>>> &tree){
    dep[node] = depth;
    pref[node] = pref[parent] + val;
    
    par[node][0] = parent;
    
    for(int i=1; i<20; i++){
        if(par[node][i-1] != 0){
            par[node][i] = par[par[node][i-1]][i-1];
        }
        else{
            par[node][i] = 0;
        }
    }
    
    for(auto [child, value]: tree[node]){
        if(child != parent){
            dfs(child, node, depth+1, value, dep, pref, par, tree);
        }
    }
}

int lca(int u, int v, vector<int> &dep, vector<vector<int>> &par){
    if(dep[u] < dep[v]){
        swap(u, v);
    }
    
    int diff = dep[u] - dep[v];
    
    for(int i=19; i>=0; i--){
        if(diff&(1<<i)){
            u = par[u][i];
        }
    }
    
    if(u==v){
        return u;
    }
    
    for(int i=19; i>=0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    return par[u][0];
}

void solve(){
    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> tree(n+1);
    
    for(int i=0; i<n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    
    vector<int> dep(n+1, 0), pref(n+1, 0);
    vector<vector<int>> par(n+1, vector<int>(20, 0));
    
    dfs(1, 0, 0, 0, dep, pref, par, tree);
    
    int q;
    cin >> q;
    
    while(q--){
        int u, v;
        cin >> u >> v;
        
        int LCA = lca(u, v, dep, par);
        
        cout << pref[u] + pref[v] - 2*pref[LCA] << endl;
    }
}

int main(){
    int t = 1;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
