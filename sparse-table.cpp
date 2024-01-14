template <typename T>
struct SparseTable {
    int n, LOG=19;
    vector<vector<T>> seg;
    SparseTable(int _n, vector<T> &a) : n(_n) {
        seg.assign(n,vector<int>(LOG));
        for(int i=0; i<n; ++i) seg[i][0]=a[i];
        for(int p=1; p<LOG; p++){
            for(int i=0; i+(1<<p)-1<n; i++){
                seg[i][p]=std::min(seg[i][p-1],seg[i+(1<<(p-1))][p-1]);
            }
        }
    }
    T query(int l, int r){
        int p=31-__builtin_clz(r-l+1);
        return std::min(seg[l][p],seg[r+1-(1<<p)][p]);
    }
};
