#include <bits/stdc++.h>
using namespace std;

vector<int> p;

void generate(string &s){
  // O(n)
  // p[i] is the length of longest prefix 
  // in [0,i) which is also a suffix of this substring
  int n=s.size();
  p.resize(n+1);
  p[0]=-1;
  for(int i=1; i<=n; i++){
    int k=p[i-1];
    while(k>=0 && s[k]!=s[i-1]){
      k=p[k];
    }
    p[i]=k+1;
  }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    string s,t;
    cin>>s>>t;
    string N=t+'!'+s;
    generate(N);
    for(int i=0; i<=n; i++) cout<<p[i]<<' ';
    return 0;
}