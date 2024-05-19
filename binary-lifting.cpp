// run init (note graph is a directed tree)

const int LOG=20; // LOG = log2(N)

vector<vector<int>> up, adj; 
vector<int> dep, par;

void dfs(int i){
        for(int j:adj[i]){
                dep[j]=dep[i]+1, up[j][0]=i;
                for(int k=1; k<LOG; ++k){
                        up[j][k]=up[up[j][k-1]][k-1];
                }
                dfs(j);
        }
}

void init(int root){
        up[root][0]=root, dep[root]=0;
        dfs(root);
}

int query(int u, int v){
        if(dep[u]<dep[v]) swap(u,v);
        int D=dep[u]-dep[v];
        for(int j=0; j<LOG; ++j){
                if(D&(1<<j)) u=up[u][j];
        }
        if(u==v){
                cout<<u<<'\n'; 
                return;
        }
        for(int j=LOG-1; ~j; --j){
                if(up[u][j]!=up[v][j]) u=up[u][j], v=up[u][j];
        }
        cout<<up[u][0]<<'\n';
}
