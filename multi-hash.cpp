// M, p = (1500450271,21), (2860486313,37)

template <typename T> 
T binpow(T x, T n, T m){  // use m=1e9+7
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
                h.resize(N);
                p.resize(N);
                i.resize(N);
                int inv=binpow(P,M-2,M);
                h[0]=(s[0]-'a'+1), p[0]=1, i[0]=1;
                for(int j=0; j<N; ++j){
                        p[j]=(p[j-1]*P)%M;
                        i[j]=(i[j-1]*inv)%M;
                        h[j]=(h[j-1]+(p[j]*(s[j]-'a'+1))%M)%M;
                }
        }
        int get_hash(int l, int r){  // 0-base index
                int ret=h[r]-(l ? h[l-1] : 0ll);
                ret=(ret%M+M)%M;
                return (ret*i[l])%M;
        }
};
