vector<vector<int>> gr, rg;
vector<int> col, seen, p;
int n, m, k;
 
void dfs1(int u){
        seen[u]=1;
        for(int v:gr[u]){
                if(!seen[v]) dfs1(v);
        }
        p.push_back(u);
}
 
void dfs2(int u){
        seen[u]=1;
        for(int v:rg[u]){
                if(!seen[v]) dfs2(v);
        }
        col[u]=k;
}
 
vector<int> kosaraju(){
// input : read graph
// output : vector containing colors for all nodes
        
        k=0;
        gr.resize(n);
        rg.resize(n);
        col.resize(n);
        seen.resize(n);
        for(int i=0; i<n; ++i){
                if(!seen[i]) dfs1(i);
        }
        seen.assign(n,0);
        reverse(p.begin(),p.end());
        for(int x:p){
                if(!seen[x]){
                        k++, dfs2(x);
                }
        }
        return col;  // colors of all vertices
}
