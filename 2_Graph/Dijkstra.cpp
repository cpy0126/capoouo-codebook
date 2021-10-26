vector<pii>edge[mxn];
int dis[mxn],vis[mxn];
void dijkstra(int s)
{
  memset(dis,0x7f,sizeof(dis));
  dis[s]=0;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  pq.emplace(0,s);
  while(pq.size()){
    int now=pq.top().Y;
    pq.pop();
    if(vis[now])continue;
    vis[now]=1;
    for(pii e:edge[now]){
      if(!vis[e.X]&&dis[e.X]>dis[now]+e.Y){
        dis[e.X]=dis[now]+e.Y;
        pq.emplace(dis[e.X],e.X);
      }
    }
  }
}