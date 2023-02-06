#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>>g;
vector<int>dist(100001, -1);

void bfs(int i){
    queue<int>q;
    q.push(i);
    dist[i]=0;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int u:g[v]){
            if(dist[u]==-1){
                q.push(u);
                dist[u]=dist[v]+1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}