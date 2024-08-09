// snippet from 1928D 

int lb=1, rb=ts+1;
while(rb>lb+3){
        // hill shape
        int m1=lb+(rb-lb)/3;
        int m2=rb-(rb-lb)/3;
        if(f(m1)<f(m2)){
                lb=m1; 
        }else{
                rb=m2;
        }
}
int ans=0;
for(int d=lb; d<=rb; ++d){
        ans=max(ans,f(d));
}
