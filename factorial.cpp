const int64_t MOD=1e9+7;  // prime
const int mxN=200005;

vector<int64_t> fac(mxN), inv(mxN), f(mxN);

void build_combination(){
    fac[0]=fac[1]=inv[0]=inv[1]=f[0]=f[1]=1;
    for(int i=2; i<mxN; i++){
        fac[i]=fac[i-1]*i%MOD;
        f[i]=(MOD-MOD/i)*f[MOD%i]%MOD;  
        inv[i]=inv[i-1]*f[i]%MOD;
    }
}
int64_t C(int n, int r){
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}
