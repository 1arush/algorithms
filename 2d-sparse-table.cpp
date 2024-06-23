// all coordinates and queries are 1-base

const int MXN=505, LOG=10;

int a[MXN][MXN], st[MXN][MXN][LOG][LOG], n, m;

void preprocess(){
        for(int i=1; i<=n; ++i){
                for(int j=1; j<=m; ++j){
                        st[i][j][0][0]=a[i][j];
                }
        }
        for(int k=1; k<LOG; ++k){
                for(int i=1; i+(1<<k)-1<=n; ++i){
                        for(int j=1; j<=m; ++j){
                                st[i][j][k][0]=max(st[i][j][k-1][0],st[i+(1<<(k-1))][j][k-1][0]);
                        }
                }
        }
        for(int l=1; l<LOG; ++l){
                for(int k=0; k<LOG; ++k){
                        for(int i=1; i+(1<<k)-1<=n; ++i){
                                for(int j=1; j+(1<<l)-1<=m; ++j){
                                        st[i][j][k][l]=max(st[i][j][k][l-1],st[i][j+(1<<(l-1))][k][l-1]);
                                }
                        }
                }
        }
}

int query(int x1, int y1, int x2, int y2){
        if(x2<x1 || y2<y1 || x1<1 || y1<1 ||x2>n || y2>m) return -1;
        int a=31-__builtin_clz(x2-x1+1);
        int b=31-__builtin_clz(y2-y1+1);
        return max(max(st[x1][y1][a][b],
                       st[x2-(1<<a)+1][y1][a][b]),
                   max(st[x1][y2-(1<<b)+1][a][b],
                       st[x2-(1<<a)+1][y2-(1<<b)+1][a][b]));        
}
