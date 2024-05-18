const int MXN=1e6+6;
vector<int> lp(MXN), pr;

for(ll i=2; i<=N; ++i){
        if(lp[i]==0){
                lp[i]=i;
                pr.push_back(i);
        }
        for(ll j=0; i*pr[j]<=N; ++j){
                lp[i*pr[j]]=pr[j];
                if(pr[j]==lp[i]) break;
        }
}
