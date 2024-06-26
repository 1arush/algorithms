struct unionfind {
        vector<int> sz, p;
        unionfind(int n){
                sz.assign(n,1), p.resize(n);
                iota(p.begin(),p.end(),0);
        }
        int leader(int a){
                return (a==p[a] ? a : p[a]=leader(p[a]));
        }
        bool same(int a, int b){
                a=leader(a), b=leader(b);
                return a==b;
        }
        void unite(int a, int b){  // union by size
                a=leader(a), b=leader(b);
                if(sz[a]<sz[b]) swap(a,b);
                if(a!=b) p[b]=a, sz[a]+=sz[b];
        }
};
