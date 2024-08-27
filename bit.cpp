// get(x)=sum of [1..x]
// add(x,v)=add v to a[x]

const int nax=2e5+5;

vector<int> fen(nax);
int n;

void reset(int sz){
        for(int i=0; i<=sz; ++i) fen[i]=0;
}

int get(int x){
        int ret=0;
        for(; x>0; x-=x&-x) ret+=fen[x];
        return ret;
} 

void add(int x, int v){
        for(; x<=n; x+=x&-x) fen[x]+=v;
}
