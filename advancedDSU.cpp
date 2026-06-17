#include<bits/stdc++.h>
using namespace std;

vector<int> pteam, teamSize, teams_par;

class DSU{
public:
    int n, m;
    
    DSU(int l, int k){
        n = l;
        m = k;
        pteam.resize(n+1, -1);
        teams_par.resize(m+1);
        teamSize.resize(m+1, 0);
        
        for(int i=1; i<=m; i++){
            teams_par[i] = i;
        }
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        
        if(rx == ry){
            return;
        }
        
        teams_par[rx] = ry;
        teamSize[ry] += teamSize[rx];
    }
    
    int root(int ind){
        int x = ind;
        while(x!=teams_par[x]){
            teams_par[x] = teams_par[teams_par[x]];
            x = teams_par[x];
        }
        
        return x;
    }
    
    bool check(int x, int y){
        if(root(x) == root(y)){
            return true;
        }
        
        return false;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n, m);
    
    int q;
    cin >> q;
    
    while(q--){
        int type;
        cin >> type;
        
        if(type == 1){
            int x, a;
            cin >> x >> a;
            
            if(pteam[x] != -1){
                int xteam = dsu.root(pteam[x]);
                teamSize[xteam]--;
            }
            
            pteam[x] = a;
            int xteam = dsu.root(pteam[x]);
            teamSize[xteam]++;
        }
        else if(type == 2){
            int a, b;
            cin >> a >> b;
            
            dsu.unite(a, b);
        }
        else if(type == 3){
            int x, y;
            cin >> x >> y;
            
            int rx = dsu.root(x);
            int ry = dsu.root(y);
            
            if(dsu.check(rx, ry)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            int a;
            cin >> a;
            
            cout << teamSize[dsu.root(a)] << endl;
        }
    }
    
    
    return 0;
}
