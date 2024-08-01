const int mod=1e9+7;

int binpow(int x, int n){
        int ret=1;
        while(n){
                if(n&1) ret=ret*x%mod;
                x=x*x%mod, n>>=1;
        }
        return ret;
}

int inverse(int x){  // mod is prime
        return binpow(x,mod-2);
}
