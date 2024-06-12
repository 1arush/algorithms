const int M=1e9+7, MXN=1e6+6;

vector<int> fac(MXN), inv(MXN), ifac(MXN);

void factorial(){
        fac[1]=inv[1]=ifac[1]=1;
        for(int i=2; i<MXN; ++i){
                fac[i]=fac[i-1]*i%M;
                inv[i]=(M-(M/i)*inv[M%i]%M)%M;
                ifac[i]=ifac[i-1]*inv[i]%M;
        }
}

int C(int n, int r){
        if(n==r) return (int)1;
        return fac[n]*ifac[r]%M*ifac[n-r]%M;
}
