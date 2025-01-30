#include<bits/stdc++.h>
using namespace std;

class Disjoint {
	vector<int> rank, parent;
	
	public: 
		Disjoint(int n) {
			rank.resize(n+1, 0);
			parent.resize(n+1);	
			for(int i=0; i<=n; i++){
				parent[i] = i;
			}
		}
		
		int findParent(int node){
			if(node == parent[node]){
				return node;
			}
			
			return parent[node] = findParent(parent[node]);
		}
		
		void unionByRank(int u, int v){
			int ulp_u = findParent(u);
			int ulp_v = findParent(v);
			
			if(rank[ulp_u] == rank[ulp_v]){
				return;
			}
			
			if(rank[ulp_u] < rank[ulp_v]){
				rank[ulp_u] = ulp_v;
			}
			else if(rank[ulp_v] < rank[ulp_u]){
				rank[ulp_v] = ulp_u;
			}
			else{
				rank[ulp_v] = ulp_u;
				rank[ulp_u]++;
			}
		}
};

int main(){
	Disjoint ds(7);
	
	ds.unionByRank(1, 2);
	ds.unionByRank(2, 3);
	ds.unionByRank(3, 4);
	ds.unionByRank(4, 5);
	ds.unionByRank(5, 6);
	ds.unionByRank(6, 7);
	
	if(ds.findParent(3) == ds.findParent(4)){
		cout<<"SAME"<<endl;
	}
	else{
		cout<<"NOT SAME"<<endl;
	}
	return 0;
}