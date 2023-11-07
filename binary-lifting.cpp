#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

const int N=2e5+5, LOG=19; // LOG = log2(N)

vector<vector<int>> up(N,vector<int> (LOG)); 
vector<int> par(N,0);

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,m;
  cin>>n;
  // m = n-1 , root = 1
  for(int i=1; i<=n; i++){
    cin>>par[i];
    up[i][0]=(i==par[i] ? -1 : par[i]);
  }
  for(int p=1; p<LOG; p++){
    for(int i=1; i<=n; i++){
      int old=up[i][p-1];
      up[i][p]=up[old][p-1];
    }
  }
  return 0;
}