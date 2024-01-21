vector<int> dist(N,1e18);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
pq.emplace(0,start), dist[start]=0;
while(!pq.empty()){
    auto [d,u]=pq.top();
    pq.pop();
    if(d>dist[u]) continue;
    for(auto [v,w]:gr[u]){
        if(d+w<dist[v]){
            dist[v]=d+w;
            pq.emplace(dist[v],v);
        }
    }
}
