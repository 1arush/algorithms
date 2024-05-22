// only used for 1-indexing
// if using for 0-base, add 1 to all indices

const int mxN=2e5+5;
int fen[mxN], n;

void init(int sz){
        for(int i=0; i<=sz; ++i) fen[i]=0;
}

void get(int x){
        int ret=0;
        for(; x>0; x-=x&-x) ret+=fen[x];
        return ret;
} 

void add(int x, int v){
        for(; x<=n; x+=x&-x) fen[x]+=v;
}
