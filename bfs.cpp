queue<int>q;
q.push(i), dist[i]=0;
while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:gr[u]){
                if(dist[v]==-1){
                        q.push(v);
                        dist[v]=dist[u]+1;
                }
        }
}
