#include <bits/stdc++.h>
#define int long long
using namespace std;

int M1=277535577223, p1=7;
int M2=257778788987, p2=11;

struct hashing {
    int n, M, p;
    string s;
    vector<int> cnt, hash, ohash, zhash, p_pow;
    hashing(int sz, string &str, int modulus, int base){
        n=sz, M=modulus, p=base, s=str;
    }
    void init(int n){
        cnt.assign(n,0), hash.assign(n,0), ohash.assign(n,2);
        zhash.assign(n,1), p_pow.assign(n,1);
        auto char_hash=[&](char ch){
            return (ch=='0' ? 1 : 2);
        };
        hash[0]=char_hash(s[0]), cnt[0]=(s[0]=='0');
        for(int i=1; i<n; i++){
            p_pow[i]=(p_pow[i-1]*p)%M;
            hash[i]=(hash[i-1]+p_pow[i]*char_hash(s[i])%M)%M;
            ohash[i]=(ohash[i-1]+p_pow[i]*char_hash('1')%M)%M;
            zhash[i]=(zhash[i-1]+p_pow[i]*char_hash('0')%M)%M; 
            cnt[i]=cnt[i-1]+(s[i]=='0');
        }
    }
    int z_count(int l, int r){
        if(l>r) return 0;
        return (cnt[r]-(l ? cnt[l-1] : 0));
    }
    int get_hash(int l, int r){
        if(l>r) return 0; 
        return (hash[r]-(l ? hash[l-1] : 0));
    }
    int get_z_hash(int l, int r){
        if(l>r) return 0;
        return (l ? zhash[r]-zhash[l-1] : zhash[r]);
    }
    int get_o_hash(int l, int r){
        if(l>r) return 0;
        return (l ? ohash[r]-ohash[l-1] : ohash[r]);
    }
    // "procedure" is specific to problem
    int procedure(int l, int r){
        int zer=z_count(l,r);
        int cur=(get_hash(0,l-1)+get_hash(r+1,n-1)+M)%M;
        cur=(cur+M)%M;
        cur=(cur+get_z_hash(l,l+zer-1)+M)%M;
        cur=(cur+get_o_hash(l+zer,r)+M)%M;
        return (cur+M)%M;
    }
};

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int t_;
    cin>>t_;
    while(t_--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        hashing h1(n,s,M1,p1);
        hashing h2(n,s,M2,p2);
        h1.init(n), h2.init(n);
        set<pair<int,int>> v;
        while(m--){
            int l,r;
            cin>>l>>r;
            --l, --r;
            // [0...l-1] [000111] [r+1...n-1]
            // [l..l+zer-1] [l+zer..r]
            int left=h1.procedure(l,r);
            int right=h2.procedure(l,r);
            v.emplace(left,right);
        }
        cout<<(int)v.size()<<'\n';
    }
    return 0;
}
