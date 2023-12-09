struct FenwickTree{
  int N;
  vector<int64_t> BIT;
  void init(int n){
    N=n;
    BIT.assign(N,0LL);
  }

  int64_t query(int r){
    int64_t ret=0;
    for(; r>=0; r=(r&(r+1))-1) ret+=BIT[r];
    return ret;
  }

  void add(int i, int v){
    for(; i<N; i=i|(i+1)) BIT[i]+=v;
  }
};