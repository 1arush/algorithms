// finding bridges offline in O(n+m) using dfs

vector<vector<int>> gr;
vector<int> tin, low, vis;
int t;

void dfs(int u, int p){
        vis[u]=1;
        tin[u]=low[u]=t++;
        for(int v:gr[u]){
                if(v==p) continue;
                if(vis[v]){
                        low[u]=min(low[u],tin[v]);       
                }else{
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                        if(low[v]>tin[u]){  
                                cout<<u<<' '<<v<<'\n';
                                // bridge :: back-edge iff low[v]<=tin[u]
                        }
                }
        }
}

void bridges(){
        t=0; 
        gr=vector<vector<int>>(n);
        tin=vector<int>(n);
        low=vector<int>(n);
        vis=vector<int>(n);
        // read graph 
        // (no multiple edges)
        for(int i=0; i<n; ++i){
                if(!vis[i]){  // each connected component
                        dfs(i,-1);
                }
        }
}
