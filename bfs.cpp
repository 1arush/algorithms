vector<int> bfs(int src){
        vector<int> dist(n);
        queue<int> q;
        q.push(src), dist[src]=0;
        while(!q.empty()){
                int u=q.front(); q.pop();
                for(int v:gr[u]){
                        if(dist[v]==-1){
                                q.push(v);
                                dist[v]=dist[u]+1;
                        }
                }
        }
        return dist;
}
