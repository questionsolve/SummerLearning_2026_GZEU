#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(vector<vector<ll>> &graph,map<pair<ll,ll>,ll> &dist,vector<ll> &MIN_dist,ll s)
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > MIN_dist[u]) continue;   
        for(auto &ele : graph[u])
        {
            if(MIN_dist[u]+dist[{u,ele}]<MIN_dist[ele])
            {
                MIN_dist[ele] = MIN_dist[u]+dist[{u,ele}];
                pq.push({MIN_dist[ele], ele});
            }
        }
    }
}
int main()
{
    ll n, m ,s,t;
    cin>>n>>m>>s>>t;
    map<pair<ll,ll>,ll> dist;
    vector<vector<ll>> graph(n+1);
    vector<ll> MIN_dist(n+1,LLONG_MAX);
    MIN_dist[s]=0;
    for(int i = 0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        dist[{u,v}] = w;
        dist[{v,u}] = w;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Solve(graph,dist,MIN_dist,s);
    cout<<MIN_dist[t]<<endl;
    return 0;
}