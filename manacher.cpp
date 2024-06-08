// works with 0-base indicing

vector<int> manacher(string t){
        // modify like #_#_#_..._#
        // now just find odd length pals
        string s;
        for(auto c:t){
                s+='#', s+=c;
        }
        s+='#';
        // manacher_odd routine
        int n=s.size();
        s='@'+s+'$';
        vector<int> p(n+2);
        int l=1, r=1;
        for(int i=1; i<=n; ++i){
                p[i]=max((int)0,min(r-i,p[l+r-i]));
                while(s[i-p[i]]==s[i+p[i]]) ++p[i];
                if(i+p[i]>r){
                        l=i-p[i], r=i+p[i];
                }
        }
        return vector<int>(p.begin()+1,p.end()-1);
}

// how to use?
vector<int> a=manacher(s);
for(int i=0; i<(int)a.size(); ++i){
        if(i&1){
                // odd
                // center is i/2
                // length is a[i]-1
                cout<<s.substr(i/2-(a[i]-1)/2,a[i]-1)<<'\n';
        }else{
                // even
                // length is a[i]-1
                // left is (i-a[i]+2)/2
                cout<<s.substr((i-a[i]+2)/2,a[i]-1)<<'\n';
        }
} 
