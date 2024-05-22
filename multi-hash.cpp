// M, p = (1500450271,21), (2860486313,37)

template <typename T> 
T binpow(T x, T n, T m=MOD){  // MOD=1e9+7
        T ret=1;
        while(n){
                if(n&1) ret=(ret*x)%m;
                x=(x*x)%m; n>>=1;
        }
        return ret;
}

struct hashing {
        int N, M, P;
        vector<int> h, p, i;

        void init(string &s, int _M, int _P){
                N=s.size(), M=_M, P=_P;
                h.resize(n);
                p.resize(n);
                i.resize(n);
                int inv=binpow(P,M-2,M);
                h[0]=(s[0]-'a'+1), p[0]=1, i[0]=1;
                for(int i=0; i<N; ++i){
                        p[i]=(p[i-1]*P)%M;
                        i[i]=(i[i-1]*inv)%M;
                        h[i]=(h[i-1]+(p[i]*(s[i]-'a'+1))%M)%M;
                }
        }
        int get_hash(int l, int r){  // 0-base index
                int ret=h[r]-(l ? h[l-1] : 0ll);
                ret=(ret%M+M)%M;
                return (ret*i[l])%M;
        }
};
