#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

tuple<long long,long long,long long> GCD(long long a, long long b){    // returns solution (x,y) and gcd(a,b)
    if(b==0) return make_tuple(1,0,a);
    tuple<long long,long long,long long> S=GCD(b, a%b);
    long long x=get<0> (S), y=get<1> (S), d=get<2> (S);
    return make_tuple(y, x-(a/b)*y, d);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    long long a, b, c; cin>>a>>b>>c;
    tuple<long long,long long,long long> t;
    t=GCD(a, b);
}