// Point update range get
template <typename T>
struct SegmentTree {
    int sz=1, n;
    vector<T> tree;
    SegmentTree(int _n) : n(_n) {
        while(sz<n) sz<<=1;
        tree.resize(2*sz);
    }
    void set(int i, T v, int x, int lx, int rx){
        if(rx-lx==1){
            tree[x]=v; return;
        }
        int m=(lx+rx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    T query(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx<=l) return (T)0;
        if(lx>=l && rx<=r) return tree[x];
        int m=(lx+rx)/2;
        auto m1=query(l,r,2*x+1,lx,m);
        auto m2=query(l,r,2*x+2,m,rx);
        return m1+m2;
    }
};

// Range update point get
template <typename T>
struct SegmentTree {
    int sz=1, n;
    vector<T> tree;
    SegmentTree(int _n) : n(_n) {
        while(sz<n) sz<<=1;
        tree.resize(2*sz);
    }
    void add(int l, int r, T v, int x, int lx, int rx){
        if(l>=rx || r<=lx) return;
        if(l<=lx && r>=rx){
            tree[x]+=v; return;
        }
        int m=(lx+rx)/2;
        add(l,r,v,2*x+1,lx,m);
        add(l,r,v,2*x+2,m,rx);
    }
    T get(int i, int x, int lx, int rx){
        if(rx-lx==1) return tree[x];
        int m=(lx+rx)/2;
        T v=(i<m ? get(i,2*x+1,lx,m) : get(i,2*x+2,m,rx));
        return tree[x]+v;
    }
};
