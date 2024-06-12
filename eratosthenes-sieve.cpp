const int MXN=1e6+6;

vector<int> lp(MXN);

void sieve(){
        for(int i=2; i<MXN; ++i){
                if(lp[i]==0){
                        lp[i]=i;
                }
                for(int j=2*i; j<MXN; j+=i){
                        lp[j]=(lp[j]==0 ? i : min(lp[j],i));
                }
        }
}
