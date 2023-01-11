#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
// Also applicable to finding least element to the right of 'x'
int main(){
    int n,x; cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=-1; // a[l] < x
    int r=n;  // a[r] >= x
    while(r>l+1){
        int m=(l+r)/2;
        if(a[m]<x) l=m;
        else r=m;
    }
    cout<<r+1<<"\n";
}