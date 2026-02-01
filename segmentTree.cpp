class SegTree{
public:
    int len;
    vector<int> t;
    
    SegTree(int l){
        len = l;
        t.resize(4*len);
    }
    
    void build(vector<int> &a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
            return;
        }
        
        int tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        
        t[v] = t[2*v] + t[2*v+1];
    }
    
    int query(int v, int tl, int tr, int l, int r){
        if(tl>r || tr<l){
            return 0;
        }
        if(l<=tl && r>=tr){
            return t[v];
        }
        
        int tm = (tl+tr)/2;
        int leftAns = query(2*v, tl, tm, l, r);
        int rightAns = query(2*v+1, tm+1, tr, l, r);
        
        return leftAns + rightAns;
    }
    
    void update(int v, int ele, int id, int tl, int tr){
        if(tl == id && tr == id){
            t[v] = ele;
        }
        
        int tm = (tl+tr)/2;
        update(2*v, ele, id, tl, tm);
        update(2*v+1, ele, id, tm+1, tr);
        
        t[v] = tv[2*v] + tv[2*v+1];
    }
    
};
