// find a cycle and print edge-numbers as in input

vector<vector<pair<int,int>>> gr;
vector<int> col, ans;
vector<pair<int,int>> par;
int n, m;
bool f=0;

void dfs(int u){
        col[u]=1;
        for(auto [v,id]:gr[u]){
                if(col[v]==0 && !f){
                        par[v]={u,id};
                        dfs(v);
                }
                else if(col[v]==1 && !f){
                        f=1;  // cycle found
                        ans.push_back(id);
                        for(int x=u; x!=v; x=par[x].first) ans.push_back(par[x].second);
                        reverse(ans.begin(),ans.end());
                }
        }
        col[u]=2;
}

void cycle_find(){
        gr.resize(n);
        col.resize(n);
        par.assign(n,-1);
        for(int i=0; i<m; ++i){
                // input graph and store edge-number
                int u,v;
                cin>>u>>v;  // di-graph
                gr[u].emplace_back(v,i);
        }
        for(int i=0; i<n; ++i){
                if(col[i]==0 && !f) dfs(i);
        }
        if(!f) cout<<-1<<'\n'; 
        else{
                cout<<(int)ans.size()<<'\n';
                for(int x:ans){
                        cout<<x<<' ';
                }
                cout<<'\n';
        }     
}
