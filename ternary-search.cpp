int L=l, R=n;
auto f=[&](int l, int r)-> int {
    int s=pf[r]-pf[l-1];
    // sum of (u..u-s+1)
    return s*(2ll*u-s+1)/2;
};
while(R-L>2){
    // convex function (hill shape)
    int M1=L+(R-L)/3;
    int M2=R-(R-L)/3;
    
    int f1=f(l,M1);
    int f2=f(l,M2);

    if(f1<f2) L=M1;
    else R=M2;
}
// check manually in [L,L+2]
if(L+1<=n && f(l,L+1)>f(l,L)) ++L;
if(L+1<=n && f(l,L+1)>f(l,L)) ++L;
