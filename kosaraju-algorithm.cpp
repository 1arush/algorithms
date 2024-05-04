#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> gr, rg;
vector<int> col, seen, p;
int k=0;
 
void dfs1(int u){
        seen[u]=1;
        for(int v:gr[u]){
                if(seen[v]) continue;
                dfs1(v);
        }
        p.push_back(u);
}
 
void dfs2(int u){
        seen[u]=1;
        for(int v:rg[u]){
                if(seen[v]) continue;
                dfs2(v);
        }
        col[u]=k;
}
 
int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif
 
// input : graph
// output : vector 'col' containing labels for all nodes
        
        int n;
        cin>>n;
        gr.resize(n);
        rg.resize(n);
        col.resize(n);
        seen.resize(n);
        int m;
        cin>>m;
        while(m--){
                int u,v;
                cin>>u>>v;
                // --u, --v;
                gr[u].push_back(v);
                rg[v].push_back(u);
        }
        for(int i=0; i<n; ++i){
                if(!seen[i]){
                        dfs1(i);
                }
        }
        seen.assign(n,0);
        reverse(p.begin(),p.end());
        for(int x:p){
                if(!seen[x]){
                        dfs2(x), ++k;
                }
        }
        for(int i=0; i<n; ++i){
                cout<<col[i]<<' '; // color of each node
        }
        return 0;
}
