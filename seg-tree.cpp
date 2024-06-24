struct Segtree {  // [l,r] inclusive
        int sz=1, NOP=-1;
        vector<int> tree;

        void init(int n){
                while(sz<n) sz<<=1;
                tree.resize(2*sz);
        }

        void apply(int &a, int b){  // addition
                if(b==NOP) return;
                if(a==NOP) a=0;
                a+=b;
        }

        void push(int x, int lx, int rx){
                if(lx==rx) return;
                apply(tree[2*x+1],tree[x]);
                apply(tree[2*x+2],tree[x]);
                tree[x]=NOP;
        }

        void add(int l, int r, int v, int x, int lx, int rx){
                push(x,lx,rx);
                if(lx>=l && rx<=r){
                        apply(tree[x],v); 
                        return;
                }
                if(rx<l || lx>r){
                        return;
                }
                int m=(lx+rx)/2;
                add(l,r,v,2*x+1,lx,m);
                add(l,r,v,2*x+2,m+1,rx);
        }

        void add(int l, int r, int v){
                add(l,r,v,0,0,sz-1);
        }

        int get(int i, int x, int lx, int rx){
                push(x,lx,rx);
                if(lx==rx){
                        return tree[x];
                }
                int m=(lx+rx)/2;
                int res;
                if(i<=m){
                        res=get(i,2*x+1,lx,m);
                }else{
                        res=get(i,2*x+2,m+1,rx);
                }
                apply(res,tree[x]);
                return res;
        }

        int get(int i){
                return get(i,0,0,sz-1);
        }
};
