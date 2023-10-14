#include <bits/stdc++.h>
using namespace std;

const int N=1e6+1;
vector<int> parent[N], rank[N];

void make_set(int v){
  parent[v]=v;
  rank[v]=0;
}

int find_set(int v){
  if(v==parent[v]) return v;
  return parent[v]=find_set(parent[v]);
}

void unite_sets(int a, int b){
  a=find_set(a);
  b=find_set(b);
  if(a!=b){
    if(rank[a]<rank[b]) swap(a,b);
    parent[b]=a;
    if(rank[a]==rank[b]) rank[a]++;
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  // fill main function
  return 0;
}