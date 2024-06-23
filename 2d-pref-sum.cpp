// coordinates are 1-base: [1,n][1,m]

const int MXN=4005;

int pf[MXN][MXN], a[MXN][MXN], n, m;

void init(){
        for(int i=1; i<=n; ++i){
                for(int j=1; <=m; ++j){
                        pf[i][j]=a[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
                }
        }
} 

int matquery(int x1, int y1, int x2, int y2){
        // smaller coordinates first
        if(x2<x1 || y2<y1 || x1<1 ||y1<1 || x2>n || y2>m) return -1;
        return pf[x2][y2]-pf[x2][y1-1]-pf[x1-1][y2]+pf[x1-1][y1-1];
}
