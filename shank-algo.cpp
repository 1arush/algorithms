int pow(int g, int x, int M){
        x=(x%M+M)%M;
        int ret=1;
        while(x){
                if(x&1) ret=(ret*g)%M;
                x>>=1, g=(g*g)%M;
        }
        return ret;
}

int shank_algo(int g, int M, int r){
        // solves for g^x = r (mod M)
        
        // g = generator, M = modulus, r = value of mod
        vector<pair<int,int>> f, s;
        int m=(int)ceil(sqrtl(M-1));
        for(int i=0; i<m; ++i){
                int g_mi=pow(g,m*i,M);
                f.emplace_back(g_mi,i);
        }
        sort(f.begin(),f.end());
        for(int i=0; i<m; ++i){
                // we have g^(-i) = g^(M-1-i) (mod M)
                int g_i=pow(g,(M-1-i),M);
                s.emplace_back(r*g_i%M,i);
        }
        sort(s.begin(),s.end());
        for(int i=0; i<m; ++i){
                auto [v,id]=f[i];
                int L=0, R=m-1;
                // binary search
                while(R>L+1){
                        int MID=(L+R)/2;
                        if(s[MID].first<=v) L=MID;
                        else R=MID;
                }
                if(s[L+1].first<=v) ++L; 
                // check answer
                if(s[L].first==v){
                        return m*id+s[L].second;
                }
        }
        return -1;
}
