#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n,m;
vector<vector<ll>> happy, dp;

ll recc(int level, int mask){
    if(level == m){
        return 0;
    }
    
    if(dp[level][mask] != -1){
        return dp[level][mask];
    }
    
    int ans = rec(level+1, mask);
    
    for(int i=0; i<n; i++){
        if(((1<<i)&mask) == 0){
            ans = max(ans, happy[level][i] + rec(level+1, mask | (1<<i)));
        }
    }
    
    return dp[level][mask] = ans;
}

int main(){
    cin >> n >> m;
    happy = vector<vector<ll>>(m, vector<ll>(n));
    dp = vector<vector<ll>>((1 << n) + 1, vector<ll>(m+1, -1));
    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> happy[i][j];
        }
    }

    ll ans = rec(0, 0);

    cout << ans << "\n";
}
