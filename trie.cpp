const int N=1e6+6, A=11;
// max nodes and alphabet size
 
int nxt[N][A], cnt[N], idx;
 
void insert(vector<int>& x, int v){
        int p=0;
        for(int u:x){
                if(!nxt[p][u]) nxt[p][u]=++idx;
                cnt[p]+=v, p=nxt[p][u];
        }
        cnt[p]+=v;
}
 
int query(vector<int>& x){
        int p=0;
        for(int u:x){
                if(!nxt[p][u]) return (int)0;
                p=nxt[p][u];
        }
        return cnt[p];
}
