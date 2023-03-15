#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

// Used to divide a digraph into strongly connected components

map<int,vector<int>>g;
map<int,vector<int>>rg;
int n,m,k=1; 
vector<bool>mark(n+1,0),mark2(n+1,0);
vector<int>label(n+1),p;

void dfs(int i){
    if(mark[i]) return;
    mark[i]=true;
    for(int x:g[i]) dfs(x);
    p.push_back(i);
}
void dfs2(int i){
    if(mark2[i]) return;
    mark2[i]=true;
    for(int x:rg[i]) dfs2(x);
    label[i]=k;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    for(int i=1;i<=n;i++) dfs(i);
    reverse(p.begin(),p.end());
    for(int i:p){
        if(!mark2[i]){
            dfs2(i); ++k;
        }
    }
    for(int i=1;i<=n;i++) cout<<label[i]<<' ';
}