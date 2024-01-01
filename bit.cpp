struct FenwickTree{
// vector<int> fen(mxN); // global
    int n; // 1-index
    void init(int _n){
        n=_n;
        for(int i=1; i<=n; ++i) fen[i]=0;
    }
    int get(int x){
        int ret=0;
        for(; x>0; x-=x&-x) ret+=fen[x];
        return ret;
    }
    void update(int x, int v){
        for(; x<=n; x+=x&-x) fen[x]+=v;
    }
};

template <typename T>
struct FenwickTree{
    int n;   // 0-index
    vector<T> fen;
    FenwickTree(int _n) : n(_n) {
        fen.resize(n);
    }
    void update(int x, T v){
        for(; x<n; x|=(x+1)) fen[x]+=v;
    }
    T get(int x){
        T v{};
        for(; x>=0; x=(x&(x+1))-1) v+=fen[x];
        return v;
    }
};
