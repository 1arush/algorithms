template<typename T>
struct HLD {
        vector<int> par, depth, heavy, head, pos, tree;
        int cur_pos, n, sz=1;
 
        void init(int _n){
                n=_n+1;
                tree=vector<int>(2*n);
                par=vector<int>(n);
                depth=vector<int>(n);
                heavy=vector<int>(n,-1);
                head=vector<int>(n);
                pos=vector<int>(n);
                cur_pos=0;
                dfs(0);
                decompose(0,0);
        }
        int combine(int x, int y){
                return std::max(x,y);
        }
        int dfs(int v){
                int s=1, max_c_size=0;
                for(int c:adj[v]){
                        if(c==par[v]) continue;
                        par[c]=v, depth[c]=depth[v]+1;
                        int c_size=dfs(c);
                        s+=c_size;
                        if(c_size>max_c_size) max_c_size=c_size, heavy[v]=c;
                }
                return s;
        }
        void decompose(int v, int h){
                head[v]=h, pos[v]=cur_pos++;
                if(heavy[v]!=-1) decompose(heavy[v],h);
                for(int c:adj[v]){
                        if(c!=par[v] && c!=heavy[v]) decompose(c,c);
                }
        }
        void seg_set(int i, int v){
                for(tree[i+=n]=v; i>1; i>>=1) tree[i>>1]=combine(tree[i],tree[i^1]);
        }
        int seg_query(int l, int r){
                int res=0;
                for(l+=n, r+=n; l<r; l>>=1, r>>=1){
                        if(l&1ll) res=combine(res,tree[l++]);
                        if(r&1ll) res=combine(res,tree[--r]);
                }
                return res;
        }
        int query(int a, int b){
                int res=0;
                for(; head[a]!=head[b]; b=par[head[b]]){
                        if (depth[head[a]]>depth[head[b]]) swap(a,b);
                        int cur_heavy_path_max=seg_query(pos[head[b]],pos[b]+1);
                        res=combine(res,cur_heavy_path_max);
                }
                if(depth[a]>depth[b]) swap(a,b);
                return combine(res,seg_query(pos[a],pos[b]+1));
        }
};
