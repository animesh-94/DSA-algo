#include<bits/stdc++.h>
using namespace std;

void findMST(vector<vector<int>> adj, vector<int> &mst, int n){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> vis(n, 0);
	
	pq.push({0, 0});
	
	int sum = 0;
	while(!pq.empty()){
		int wt = pq.top().first;
		int node = pq.top().second
		
		pq.pop();
		
		if(vis[node] == 1){
			continue;
		}
		
		vis[node] = 1;
		sum += wt;
		mst.push_back(parent);
		
		for(auto it: adj[node]){
			int adjNode = it[0];
			int ewt = it[1];
			
			if(!vis[adjNode]){
				pq.push({ewt, adjNode});
			}
		}
	}
}

int main(){
	int n = 3;
	vector<vector<int>> adj = {{0,1,5},{1,2,3},{0,2,1}};
	vector<int> mst(n);
	
	findMST(adj, mst, n);
	
	for(int i=0; i<n; i++){
		cout<<mst[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
