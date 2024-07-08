// Consider using if values are large

using i128=__int128;

void print(i128 x){
        if(x<0) putchar('-'), x=-x;
        if(x>9) print(x/10);
        putchar(x%10+'0');
}
