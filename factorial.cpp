vector<int> fac(nax), inv(nax), ifac(nax);

void factorial(){
        fac[1]=inv[1]=ifac[1]=1;
        for(int i=2; i<nax; ++i){
                fac[i]=fac[i-1]*i%mod;
                inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
                ifac[i]=ifac[i-1]*inv[i]%mod;
        }
}

int choose(int n, int r){
        if(n==r) return (int)1;
        return fac[n]*ifac[r]%mod*ifac[n-r]%mod;
}
