struct Pt {
        int x, y;
        Pt(int a=0, int b=0){
                x=a, y=b;
        }
        void read(){
                cin>>x>>y;
        }
        Pt operator -(const Pt &b) const {
                return Pt(x-b.x,y-b.y);
        }
        Pt operator +(const Pt &b) const {
                return Pt(x+b.x,y+b.y);
        }
        void operator -=(const Pt &b){
                x-=b.x, y-=b.y;
        }
        void operator +=(const Pt &b){
                x+=b.x, y+=b.y;
        }
        int dot(const Pt &b) const {
                // a . b (dot product)
                return x*b.x+y*b.y;
        }
        int cross(const Pt &b) const {
                // a x b (cross product)
                return x*b.y-y*b.x;
        }
};
