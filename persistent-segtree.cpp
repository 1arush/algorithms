// adapted from https://cses.fi/problemset/result/11533137/

struct Vertex {
        Vertex *l, *r;
        int sum;
        Vertex(int v) : l(NULL), r(NULL), sum(v) {}
        Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
                if(l) sum+=l->sum;
                if(r) sum+=r->sum;
        }
};
 
Vertex* build(vector<int>& a, int lx, int rx){
        if(rx==lx) return new Vertex(a[lx]);
        int m=(lx+rx)/2;
        return new Vertex(build(a,lx,m),build(a,m+1,rx));
}
 
Vertex* upd(Vertex* v, int i, int val, int lx, int rx){
        if(lx==rx) return new Vertex(val);
        int m=(lx+rx)/2;
        if(i<=m) 
                return new Vertex(upd(v->l,i,val,lx,m),v->r);
        else 
                return new Vertex(v->l,upd(v->r,i,val,m+1,rx));
}
 
int qry(Vertex* v, int l, int r, int lx, int rx){
        if(l>r || rx<l || lx>r) return 0;
        if(l<=lx && rx<=r) return v->sum;
        int m=(lx+rx)/2;
        return qry(v->l,l,r,lx,m)+qry(v->r,l,r,m+1,rx);
}
