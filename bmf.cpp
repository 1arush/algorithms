const int INF=1e18;

int n, m;
vector<array<int,3>> edges;

void read_graph(){
        for(int i=0; i<m; ++i){
                int a,b,w;
                cin>>a>>b>>w, --a, --b;
                array<int,3> arr {a,b,w};
                edges.push_back(arr);
                swap(arr[0],arr[1]);
                edges.push_back(arr);
        }      
}

vector<int> bellman_ford(int x){
        vector<int> dist(n,INF);
        dist[x]=0;
        for(int i=1; i<n; ++i){
                for(auto e:edges){
                        int a=e[0], b=e[1], w=e[2];
                        dist[b]=min(dist[b],dist[a]+w);
                }
        }
        return dist;
}
