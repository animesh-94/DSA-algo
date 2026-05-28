#include<bits/stdc++.h>
using namespace std;

int maxDist;
int farthestPoint;

int par[100100];

void dfs(int node, int parent, int currDist, vector<vector<int>> &tree){
    if(currDist > maxDist){
        maxDist = currDist;
        farthestPoint = node;
    }

    par[node] = parent;

    for(auto neigh: tree[node]){
        if(neigh != parent){
            dfs(neigh, node, currDist+1, tree);
        }
    }
}

int dep[100100];

int cnt;
void dfsCenter(int node, int parent, int dist, vector<vector<int>> &tree){
    if(dist == maxDist/2){
        cnt++;
    }

    dep[node] = dist;

    for(auto neigh: tree[node]){
        if(neigh != parent){
            dfsCenter(neigh, node, dist+1, tree);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<vector<int>> tree(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    maxDist = -1;
    dfs(1, 0, 0, tree);
    int startNode = farthestPoint;

    maxDist = -1;
    dfs(startNode, 0, 0, tree);
    int endNode = farthestPoint;

    int center = maxDist/2;

    int node = endNode;
    vector<int> path;
    while(node != 0){
        path.push_back(node);
        node = par[node];
    }

    reverse(path.begin(), path.end());
    int totalDiamters = 0;

    //case 1: 1 center
    if(path.size()%2 != 0){
        int c1=path[center];
        int sumOfOCounts = 0;

        int cnt1;
        cnt=0;

        for(auto it: tree[c1]){
            int beforeBracnhCount = cnt;
            dfsCenter(it, c1, 1, tree);
            int currBranch = cnt - beforeBracnhCount;

            totalDiamters += sumOfOCounts*currBranch;
            sumOfOCounts += currBranch;
        }
    }
    //case 2: 2 center
    else{
        int c1 = path[center];
        int c2 = path[center+1];

        int cnt1, cnt2;

        cnt = 0;
        dfsCenter(c1, c2, 0, tree);
        cnt1 = cnt;

        cnt=0;
        dfsCenter(c2, c1, 0, tree);
        cnt2 = cnt;

        totalDiamters = cnt1*cnt2;

        cout << totalDiamters << endl;
    }

    return 0;
}
