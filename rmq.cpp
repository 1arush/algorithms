#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

const int LOG=18;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for(int &i:a) cin>>i;
  vector<vector<int>> seg(n,vector<int>(LOG));
  auto operation=[&](int a, int b){
    return min(a,b);
  };
  auto binlog=[&](int x){
    return 31-__builtin_clz(x);
  };
  for(int i=0; i<n; i++) seg[i][0]=a[i];
  for(int p=1; p<LOG; p++){
    for(int i=0; i+(1<<p)-1<n; i++){
      seg[i][p]=operation(seg[i][p-1],seg[i+(1<<(p-1))][p-1]);
    }
  }
  while(q--){
    int l,r;
    cin>>l>>r, --l, --r;
    // 0-based index
    int p=binlog(r-l+1);
    cout<<operation(seg[l][p],seg[r+1-(1<<p)][p])<<'\n';
  }
  return 0;
}