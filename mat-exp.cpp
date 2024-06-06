vector<vector<int>> res(n,vector<int>(n));
for(int i=0; i<n; ++i){
        res[i][i]=1;  //  identity matrix
}

auto multiply=[&](vector<vector<int>> &a, vector<vector<int>> &b){
        const int n=a.size();
        vector<vector<int>> ret(n,vector<int>(n));
        for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                        for(int k=0; k<n; ++k){
                                ret[i][j]+=a[i][k]*b[k][j];
                        }
                }
        }
        return ret;
};

auto binpow=[&](int T)-> void {
        vector<vector<int>> mul(n,vector<int>(n));
        // fill multiplying matrix
        while(T){
                if(T&1) res=multiply(res,mul);
                mul=multiply(mul,mul), T>>=1;
        }
};
