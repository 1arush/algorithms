#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int n,m;
vector<vector<pii>>g;
long long dist[100001];
int p[100001];
long long inf=1e18;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    fill(dist,dist+n+1,inf);
    fill(p,p+n+1,-1);
    g.resize(n+2);
    for(int i=0;i<m;i++){
        int x,y,d; cin>>x>>y>>d;
        g[x].push_back({y,d});
        g[y].push_back({x,d});
    }
    set<pii>q;
    dist[1]=0;
    q.insert({0,1});
    while(!q.empty()){
        int v=q.begin()->second;
        q.erase(q.begin());
        for(auto t:g[v]){
            long long u=t.first;
            long long w=t.second;
            if(dist[v]+w<dist[u]){
                q.erase({dist[u],u});
                dist[u]=dist[v]+w;
                q.insert({dist[u],u});
                p[u]=v;
            }
        }
    }
    if(dist[n]==inf || p[n]==0){ cout<<-1; return 0; }
    int i=n;
    vector<int>path;
    while(p[i]!=-1){
        path.push_back(i);
        i=p[i];
    }
    path.push_back(1);
    for(int i=path.size()-1;i>=0;i--) cout<<path[i]<<' ';
}