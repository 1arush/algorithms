const int MXN=1e6+6, nb=3, M=1500450271;

int h[nb][MXN], pp[nb][MXN], ip[nb][MXN], B[nb]={37,53,61}, I[nb], n;
string s;

int binpow(int x, int n){
        int ret=1;
        while(n){
                if(n&1) ret=ret*x%M;
                x=x*x%M, n>>=1;
        }
        return ret;
}

void init(){
        // random bases
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        for(int j=0; j<nb; ++j){
                B[j]=uniform_int_distribution<int> (25,6755)(rng);
        }
        for(int j=0; j<nb; ++j){
                pp[j][0]=1, ip[j][0]=1;
                I[j]=binpow(B[j],M-2);
        }
        for(int i=1; i<MXN; ++i){
                for(int j=0; j<nb; ++j){
                        pp[j][i]=pp[j][i-1]*B[j]%M;
                        ip[j][i]=ip[j][i-1]*I[j]%M;
                }
        }
}

vector<int> hash(int l, int r){
        vector<int> a;
        for(int j=0; j<nb; ++j){
                int c=h[j][r]-(l ? h[j][l-1] : 0ll);
                c=(c%M+M)%M;
                c=c*ip[j][l]%M;
                if(c<0) c+=M;
                a.push_back(c);
        }
        return a;
}

// inside main
for(int j=0; j<nb; ++j){
        h[j][0]=s[0]-'a'+1;
}
for(int i=1; i<n; ++i){
        for(int j=0; j<nb; ++j){
                h[j][i]=(h[j][i-1]+pp[j][i]*(s[i]-'a'+1)%M)%M;
                if(h[j][i]<0) h[j][i]+=M;
        }
}
