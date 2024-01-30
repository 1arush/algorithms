#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> gr;
vector<int> col, ans;
vector<pair<int,int>> par;
int st,en,id;
bool f=0;

void dfs(int u){
    col[u]=1;
    for(auto [v,i]:gr[u]){
        if(col[v]==0 && !f){
            par[v]={u,i};
            dfs(v);
        }
        else if(col[v]==1 && !f){
            f=1;
            ans.push_back(i);
            for(int x=u; x!=v; x=par[x].first) ans.push_back(par[x].second);
            reverse(ans.begin(),ans.end());
            cout<<(int)ans.size()<<'\n';
            for(int x:ans) cout<<x<<'\n';
        }
    }
    col[u]=2;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    gr.resize(n);
    col.resize(n);
    par.assign(n,{-1,-1});
    for(int i=0; i<m; ++i){
        int u,v;
        cin>>u>>v;
        gr[u].emplace_back(v,i);
    }
    for(int i=0; i<n; ++i){
        if(col[i]==0 && !f) dfs(i);
    }
    // required output is the edge-id used in the cycle
    // printing is done inside the function and stored in bool f
    if(!f) cout<<-1<<'\n';
    return 0;
}
