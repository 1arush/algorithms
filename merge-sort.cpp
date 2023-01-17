#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define pb push_back


vi merge(vi c, vi d){
    vi r;
    c.pb(INT_MAX); d.pb(INT_MAX);
    int i=0,j=0;
    while(i<c.size()-1 || j<d.size()-1){
        if(c[i]<d[j]) r.pb(c[i++]);
        else r.pb(d[j++]);
    }
    return r;
}

vi mergesort(vi &a, int l, int r){
    if(r-l<1){
        vi t; t.pb(a[r]); return t;
    }
    int mid=(l+r)/2;
    return merge(mergesort(a,l,mid),mergesort(a,mid+1,r));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vi a(n); 
    for(int i=0;i<n;i++) cin>>a[i];
    a=mergesort(a,0,n-1);
    for(auto x:a) cout<<x<<' ';
}