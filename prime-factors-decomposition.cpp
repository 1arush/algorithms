vector<pair<int,int>> prime_factors(int x){
        vector<pair<int,int>> ret;
        for(int i=2; i*i<=x; ++i){
                if(x%i) continue;
                int cnt=0;
                while(x%i==0){
                        x/=i, ++cnt;
                }
                ret.emplace_back(i,cnt);
        }
        if(x>1) ret.emplace_back(x,1);
        return ret;
}

vector<int> divisors(int x){
        vector<int> ret;
        for(int i=1; i*i<=x; ++i){
                if(x%i==0){
                        ret.push_back(i);
                        if(i*i!=x) ret.push_back(x/i);
                }
        }
        return ret;
}
