class wunionfind {
  public:
    int *id, *sz;
    int maxi;

	//normal constructor initialization and assigning of parent value
    wunionfind(int n = N) {
        id = new int[n + 1];
        sz = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        maxi = 1;
    }

	function for finding the root of the given node
    int root(int idx) {
        int x = idx;
        while(x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }

	//function for merging the values
    bool uni(int a, int b) {
        int x = root(a), y = root(b);
        if(sz[x] < sz[y]) {
            swap(x, y);
        }
        if (x != y) {
            id[y] = x;
            sz[x] += sz[y];
            sz[y] = 0;
            maxi = max(maxi, sz[x]);
            return false;
        }
        return true;
    }

	//boolean function for the checking the parents are same
    bool check(int a, int b) {
        return (root(a) == root(b));
    }
};
