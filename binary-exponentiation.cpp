template <typename T> 
T binpow(T x, T n, T m=MOD){  // MOD=1e9+7
        T ret=1;
        while(n){
                if(n&1) ret=(res*x)%m;
                x=(x*x)%m; n>>=1;
        }
        return ret;
}
