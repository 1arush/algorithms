// tops is the topological order
vector<vector<int>> gr;
vector<int> tops, seen;

void dfs(int u){
        seen[u]=1;
        for(int v:gr[u]){
                if(seen[v]) continue;
                dfs(v);
        }
        tops.push_back(u);
}
