#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<pair<ll,int>> prime_factors_decomposition(ll x){
    vector<pair<ll,int>>f;
    for(ll i=2; i<=x/i; i++){
        pair<ll,int> p={i,0};
        while(x%i==0){
            x/=i; p.second++;
        }
        if(p.second) f.push_back(p);
    }
    if(x>1) f.push_back({x,1});
    return f;
}

vector<ll> generate_divisors(ll x){
    vector<ll> v;
    for(ll i=1; i<=x/i; i++){
        if(x%i==0){
            v.push_back(i);
            if(i!=x/i) v.push_back(x/i);
        }
    }
    return v;
}

int main(){
    ll n; cin>>n;
    vector<pair<ll,int>> k=prime_factors_decomposition(n);
    vector<ll> P=generate_divisors(n);
    for(auto x:P) cout<<x<<' '; cout<<'\n';
    for(auto x:k){
        cout<<x.first<<" "<<x.second<<"\n";
    }
 }