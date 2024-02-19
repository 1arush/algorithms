template <typename T> 
T binpow(T x, T n, T m=MOD){  // MOD=1e9+7
	T res=1;
	while(n){
		if(n&1) res=res*x%m;
		x=x*x%m; n>>=1;
	}
	return res;
}
