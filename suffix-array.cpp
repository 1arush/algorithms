#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &p, vector<int> &c){
        const int n=p.size();
        vector<int> cnt(n), pos(n), p_new(n);
        for(auto x:c){
                ++cnt[x];  // add elements
        }
        for(int i=1; i<n; ++i){
                pos[i]=pos[i-1]+cnt[i-1];  // prepare buckets
        }
        for(auto x:p){
                int i=c[x];
                p_new[pos[i]++]=x;  // add to buckets
        }
        p=p_new;
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        string s;
        cin>>s;
        s+='$';
        int n=s.size();
        vector<int> p(n), c(n);
        {
                // k = 0 : base case
                vector<pair<char,int>> a(n);
                for(int i=0; i<n; ++i){
                        a[i]={s[i],i};
                }
                sort(a.begin(),a.end());
                for(int i=0; i<n; ++i){
                        p[i]=a[i].second;
                }
                for(int i=1; i<n; ++i){
                        c[p[i]]=c[p[i-1]]+(a[i].first==a[i-1].first ? 0 : 1);
                }
        }
        int k=0;
        while((1<<k)<n){
                // k -> k+1 : iteration
                for(int i=0; i<n; ++i){
                        p[i]=(p[i]-(1<<k)+n)%n;
                }
                count_sort(p,c);
                vector<int> c_new(n);
                for(int i=1; i<n; ++i){
                        pair<int,int> pre={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
                        pair<int,int> cur={c[p[i]],c[(p[i]+(1<<k))%n]};                        
                        c_new[p[i]]=c_new[p[i-1]]+(pre==cur ? 0 : 1);
                }
                c=c_new;
                ++k;
        }
        for(int i=0; i<n; ++i){
                cout<<p[i]<<' ';
        }
        return 0;
}
