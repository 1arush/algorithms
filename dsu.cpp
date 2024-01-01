struct DSU {
    int n;
    vector<int> sz, p;
    DSU(int _n) : n(_n) {
        sz.assign(n,1), p.resize(n);
        iota(all(p),0);
    }
    int leader(int a){
        return (a==p[a] ? a : p[a]=leader(p[a]));
    }
    bool unite(int a, int b){
        a=leader(a), b=leader(b);
        if(sz[a]<sz[b]) swap(a,b);
        if(a!=b){
            p[b]=a, sz[a]+=sz[b];
            return 1;
        }
        return 0;
    }
};
