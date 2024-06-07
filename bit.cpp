// use with 0-base (works 1-base internally)
// get(x)=sum of [0..x-1]
// add(x,v)=add v to a[x]

const int MXN=2e5+5;

int fen[MXN], n;

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
