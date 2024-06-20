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
        bool operator <(const Pt &b) const {
                return make_pair(x,y)<make_pair(b.x,b.y);
        }
        int cross(const Pt &b) const { 
                return x*b.y-y*b.x;  // a x b
        }
        int triangle(const Pt &a, const Pt &b) const { 
                return (a-*this).cross(b-*this);  // pa x pb
        }
};
