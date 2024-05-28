// originally used for 1-indexing
// if using for 0-base, ++ before query
// query like : get(x) = sum[0,x]

const int mxN=2e5+5;

int fen[mxN], n;

void reset(int sz){
        for(int i=0; i<=sz; ++i) fen[i]=0;
}

int get(int x){
        int ret=0;
        for(++x; x>0; x-=x&-x) ret+=fen[x];
        return ret;
} 

void add(int x, int v){
        for(++x; x<=n; x+=x&-x) fen[x]+=v;
}
