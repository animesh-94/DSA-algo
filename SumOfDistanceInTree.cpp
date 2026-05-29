#include<bits/stdc++.h>
using namespace std;

#define int long long

int subTreeSize[200100];

void dfs(int node, int parent, vector<vector<int>> &tree){
    subTreeSize[node] = 1;
    
    for(auto neigh: tree[node]){
        if(neigh!=parent){
            dfs(neigh, node, tree);
            
            subTreeSize[node] += subTreeSize[neigh];
        }
    }
}

signed main(){
    int n;
    cin >> n;
    
    vector<vector<int>> tree(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, 0, tree);
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        ans += subTreeSize[i]*(n-subTreeSize[i]); 
    }
    
    cout << ans << endl;
    
    return 0;
}
