#include<bits/stdc++.h>
using namespace std;

class DSU{  
    public: 
    vector<int> parent, sz;
    
    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1);
        
        for(int i=1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    
    int root(int ind){
        int x = ind;
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        
        return x;
    }
    
    bool unite(int a, int b){
        int x = root(a);
        int y = root(b);
        
        if(sz[x] < sz[y]){
            swap(x, y);
        }
        
        if(x!=y){
            sz[x] += sz[y];
            sz[y] = 0;
            parent[y] = x;
            
            return false;
        }
        
        return true;
    }
    
    bool check(int a, int b){
        return (root(a) == root(b));
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    
    DSU dsu(n);
    
    while(q--){
        int mode, a, b;
        cin >> mode >> a >> b;
        
        if(mode == 0){
            dsu.unite(a, b);
        }
        else{
            if(dsu.check(a, b)){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    
    return 0;
}
