#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,m,x;
  cin>>n>>m>>x;
  vector<array<int,3>> edges;
  // input
  for(int i=0; i<m; i++){
    int a,b,w;
    cin>>a>>b>>w;
    array<int,3> arr {a,b,w};
    edges.push_back(arr);
    swap(arr[0],arr[1]);
    edges.push_back(arr);
  }
  // bellman-ford
  // O(nm)
  vector<int> dist(n+1,inf);
  dist[x]=0;
  for(int i=1; i<n; i++){
    for(auto e:edges){
      int a=e[0], b=e[1], w=e[2];
      dist[b]=min(dist[b],dist[a]+w);
    }
  }
  for(int i=1; i<=n; i++){
    cout<<dist[i]<<' ';
  }
  return 0;
}
