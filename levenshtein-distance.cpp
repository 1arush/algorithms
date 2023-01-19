#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

// Transform A -> B
// Operations allowed : 1) Changing a character
//                      2) Deleting a character
//                      3) Adding a character

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string a,b; cin>>a>>b;
    int A=a.length(), B=b.length();
    int D [A+1][B+1];
    // D [i][j] represents : Minimum operations required to reach B[0..j-1] from A[0..i-1]
    for(int i=0;i<=A;++i){
        for(int j=0;j<=B;++j){
            if(i+j==0){
                D[i][j]=i+j;
                continue;
            }
            if(a[i-1]==b[j-1]){
                D[i][j]=D[i-1][j-1];
            } else{
                D[i][j]=min(D[i-1][j-1], min(D[i][j-1], D[i-1][j]))+1;
            }
        }
    }
    cout<<D[A][B];
}