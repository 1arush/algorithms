// query with 0-base (works 1-base internally)
// get(x,y)=submatrix sum of [0..x-1][0..y-1]
// add(x,y,v)=add v to point (x,y)

const int MXN=2e3+3;

int fen[MXN][MXN], n, m;

void reset(int zx, int zy){
        for(int i=0; i<=zx; ++i){
                for(int j=0; j<=zy; ++j) fen[i][j]=0;
        }
}

int get(int x, int y){
        int ret=0;
        ++x, ++y;
        for(int i=x; i>0; i-=i&-i){
                for(int j=y; j>0; j-=j&-j) ret+=fen[i][j];
        }
        return ret;
}

void add(int x, int y, int v){
        ++x, ++y;
        for(int i=x; i<=n; i+=i&-i){
                for(int j=y; j<=m; j+=j&-j) fen[i][j]+=v;
        }
}
