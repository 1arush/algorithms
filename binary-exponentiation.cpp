#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

long long binary_power(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b&1) res=res*a;
        a*=a; b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    long long a,b; cin>>a>>b;
    cout<<binary_power(a,b);
}