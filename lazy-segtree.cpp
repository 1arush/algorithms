// it suffices to change merge and apply 
// uses inclusive queries for calling
// originally for addition and sum (more @EDU)

struct Segtree {
        int sz=1, NO_OPERATION=1e16, NEUTRAL=0;  // important!
        vector<int> lazy, tree;
        void init(int n){
                while(sz<n) sz<<=1;
                lazy.assign(2*sz,NO_OPERATION);
                tree.assign(2*sz,0LL);  // initialize
        }
        int merge(int a, int b){
                return a+b;
        }
        int apply(int a, int b, int len){
                if(b==NO_OPERATION) return a;
                return a==NO_OPERATION ? b*len : a+b*len;
        }
        void push(int x, int lx, int rx){
                if(rx-lx==1 || lazy[x]==NO_OPERATION) return;
                int m=(lx+rx)/2;
                tree[2*x+1]=apply(tree[2*x+1],lazy[x],m-lx);
                lazy[2*x+1]=apply(lazy[2*x+1],lazy[x],1);
                tree[2*x+2]=apply(tree[2*x+2],lazy[x],rx-m);
                lazy[2*x+2]=apply(lazy[2*x+2],lazy[x],1);
                lazy[x]=NO_OPERATION;
        }
        void build(int x, int lx, int rx){
                if(rx-lx==1){  // use build carefully
                        tree[x]=0; return;
                }
                int m=(lx+rx)/2;
                build(2*x+1,lx,m);
                build(2*x+2,m,rx);
                tree[x]=merge(tree[2*x+1],tree[2*x+2]);
        }
        void modify(int l, int r, int v, int x, int lx, int rx){
                push(x,lx,rx); 
                if(rx<=l || lx>=r) return;
                if(lx>=l && rx<=r){
                        lazy[x]=apply(lazy[x],v,1);
                        tree[x]=apply(tree[x],v,rx-lx); 
                        return;
                }
                int m=(lx+rx)/2;
                modify(l,r,v,2*x+1,lx,m);
                modify(l,r,v,2*x+2,m,rx);
                tree[x]=apply(merge(tree[2*x+1],tree[2*x+2]),lazy[x],rx-lx);
        }
        int calc(int l, int r, int x, int lx, int rx){
                push(x,lx,rx);
                if(rx<=l || lx>=r) return NEUTRAL;
                if(lx>=l && rx<=r) return tree[x];
                int m=(lx+rx)/2;
                auto m1=calc(l,r,2*x+1,lx,m);
                auto m2=calc(l,r,2*x+2,m,rx);
                return apply(merge(m1,m2),lazy[x],min(rx,r)-max(lx,l));
        }
        void modify(int l, int r, int v){
                modify(l,r+1,v,0,0,sz);
        }
        int calc(int l, int r){
                return calc(l,r+1,0,0,sz);
        }
};
