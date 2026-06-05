#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101];
int subTreeSize[101];
int dp[101][2][101];
vector<int> tree[101];

void dfs(int node, int parent){
    subTreeSize[node] = 1;
    
    for(int i=0; i<=k; i++){
        dp[node][1][i] = (i==1 ? arr[node] : -1e9);
        dp[node][0][i] = (i==0 ? 0 : -1e9);
    }
    
    for(auto child: tree[node]){
        dfs(child, node);
        subTreeSize[node] += subTreeSize[child];
        
        for(int a=k; a>=0; a--){
            for(int b=k; b>=0; b--){
                //trying all sum pair in 'a' and 'b' and figuring out what will be good so that my ans is maximum for that dp state
                //if i dont choose to select the node into the ans
                dp[node][0][a+b] = max(dp[node][0][a+b], dp[node][0][a] + max(dp[child][0][b], dp[child][1][b]));
                
                //trying all sum pair in 'a' and 'b' and figuring out what will be good so that my ans is maximum for that dp state
                //if i choose to select the node into the ans
                dp[node][1][a+b] = max(dp[node][1][a+b], dp[node][1][a] + dp[child][0][b]);
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, 0);
    cout << max(dp[1][0][k], dp[1][1][k]);
}

int main(){
    solve();
    
    return 0;
}
