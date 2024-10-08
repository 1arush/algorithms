// adapted from problem: 1921f
// the IDEA is to answer queries in 2 types : simulation and precomputation

int n, q;
const int rt=sqrt(n);  // maybe 450
vector<int> a(n+1);
vector<vector<int>> sum(rt,vector<int>(n+1)), one;

one=sum;

for(int d=1; d<rt; ++d){
        for(int i=1; i<=d; ++i){
                sum[d][i]=a[i];
                for(int j=i+d; j<=n; j+=d){
                        sum[d][j]=((j-i)/d+1ll)*a[j]+sum[d][j-d];
                        one[d][j]=a[j]+one[d][j-d];
                }
        }
}
while(q--){
        int s, d, k;
        cin>>s>>d>>k;
        int ans=0;
        if(d>=rt){
                // simulate query
                // ...
                for(int c=0; c<k; ++c){
                        ans+=(c+1)*a[s+c*d];
                }
        }else{
                // use precomputation
                // ...
                ans=sum[d][s+d*(k-1)]-(s-d>=1 ? sum[d][s-d] : 0ll);
                int cnt=one[d][s+d*(k-1)]-(s-d>=1 ? one[d][s-d] : 0ll);
                int f=(s%d==0ll ? d : s%d);
                ans-=max(0ll,(s-f)/d)*cnt;
        }       
        cout<<ans<<'\n';
}
