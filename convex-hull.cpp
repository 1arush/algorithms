// Pt : struct defined in point.cpp 

vector<Pt> convex_hull(vector<Pt> &a){
        sort(a.begin(),a.end());
        vector<Pt> hull;
        for(int rep=0; rep<2; ++rep){
                const int SZ=hull.size();
                for(auto C:a){
                        while((int)hull.size()-SZ>1){
                                Pt A=hull.end()[-2];
                                Pt B=hull.end()[-1];
                                if(A.triangle(B,C)<=0){
                                        break;
                                }
                                hull.pop_back();
                        }
                        hull.push_back(C);
                }
                hull.pop_back();
                reverse(a.begin(),a.end());
        }
        return hull;
}
