#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,vector<pair<int,int>>>g;
vector<int>dist(100001, INT_MAX);
vector<int>p(100001, -1);
vector<bool>mark(100001, false);

void dijkstra(int s){
    dist[s]=0;
    for(int i=0;i<n;i++){
        // select closest unmarked vertex
        int v=-1;
        for(int j=0;j<n;j++){
            if(!mark[j] && (v==-1 || dist[j]<dist[v])){
                v=j;
            }
        }
        if(dist[v]==INT_MAX) break;
        // improve the shortest path
        mark[v]=true;
        for(auto edge:g[v]){
            int t=edge.first;
            int w=edge.second;
            if(dist[v]+w<dist[t]){
                dist[t]=dist[v]+w;
                p[t]=v;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,d; cin>>x>>y>>d;
        g[x].push_back({y,d});
        g[y].push_back({x,d});
    }
    dijkstra(1);
    if(dist[n]==INT_MAX){ cout<<-1; return 0; }
    // dist[] stores all the shortest distances from 1 (in general, any i)
    int i=n;
    vector<int>path;
    while(p[i]!=-1){
        path.push_back(i);
        i=p[i];
    } path.push_back(1);
    reverse(path.begin(),path.end());
    for(int x:path) cout<<x<<' ';
}