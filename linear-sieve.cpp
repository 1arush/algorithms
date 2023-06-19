#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e7;
vector<ll> lp(N+1,0);
vector<ll> pr;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(ll i=2; i<=N; i++){
        if(lp[i]==0){
            lp[i]=i;
            pr.push_back(i);
        }
        for(ll j=0; i*pr[j]<=N; j++){
            lp[i*pr[j]]=pr[j];
            if(pr[j]==lp[i]) break;
        }
    }
}