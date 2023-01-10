#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,r; cin>>n>>r;
    ll a[n+2][n+2];
    for(ll i=1;i<=n+1;i++){ 
        a[i][1]=1;
        a[i][i]=1;
    }
    for(ll i=3;i<=n+1;i++){
        for(int j=2;j<i;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    cout<<a[n+1][r+1];
}