int binpow(int x, int n){
        int ret=1;
        while(n){
                if(n&1) ret=ret*x%M;
                x=x*x%M, n>>=1;
        }
        return ret;
}

int inverse(int x){  // prime M
        return binpow(x,M-2,M);
}
