const int mod=1e9+7, nax=1e5+5;

vector<int> fac(nax), inv(nax), ifac(nax);

void factorial(){
        fac[0]=inv[1]=ifac[0]=1;
        for(int i=1; i<nax; ++i){
                fac[i]=fac[i-1]*i%mod;
                if(i>1) inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
                ifac[i]=ifac[i-1]*inv[i]%mod;
        }
}

int choose(int n, int r){
        if(n<r || n<0 || r<0) return (int)0;
        return fac[n]*ifac[r]%mod*ifac[n-r]%mod;
}
