vector<vector<int>> res(n,vector<int>(n));
for(int i=0; i<n; ++i) res[i][i]=1;
// Identity matrix

auto multiply=[&](vector<vector<int>> &a, vector<vector<int>> &b){
  int n=a.size();
  vector<vector<int>> ans(n,vector<int>(n));
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      for(int k=0; k<n; ++k){
        ans[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  return ans;
};

auto binpow=[&](int T)->void {
  vector<vector<int>> mul(n,vector<int>(n));
  // Fill multiplying matrix
  while(T){
    if(T&1) res=multiply(res,mul);
    mul=multiply(mul,mul), T>>=1;
  }
};
