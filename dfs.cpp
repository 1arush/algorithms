#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

// @author: rushil

unordered_map<int,vector<int>>graph;
vector<bool>mark;
vector<int>topsort;

void dfs(int i){
    mark[i]=true;
    for(auto x:graph[i]){
        if(!mark[x])
            dfs(x);
    }
    topsort.push_back(i);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,m; cin>>n>>m;
    int ct=0;
    mark.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!mark[i])
            dfs(i);
    }
    
    // topsort : topologically sorted array for directed graphs
    for(int i:topsort) cout<<i<<' ';
}