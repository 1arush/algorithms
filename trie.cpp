const int N=2e5*32+500, A=2;
// max nodes and alphabet size

int nxt[N][A], cnt[N], idx;

void insert(int x, int v){
  int p=0;
  for(int i=31; ~i; --i){
    int u=(x>>i)&1;
    if(!nxt[p][u]) nxt[p][u]=++idx;
    cnt[p]+=v, p=nxt[p][u];
  }
  cnt[p]+=v;
}

int query(int x){
  x=~x;
  int p=0, res=0;
  for(int i=31; ~i; --i){
    int u=(x>>i)&1;
    if(nxt[p][u] && cnt[nxt[p][u]]){
      res+=(1<<i), p=nxt[p][u];
    }
    else p=nxt[p][!u];
  }
  return res;
}