
// P1346 [CHCI 2002 Regional Competition Juniors]电车

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void BFS(vector<vector<ll>>& graph,ll start,ll end,vector<ll>& Count)
{
    queue<ll> qe;
    qe.push(start);
    while(!qe.empty())
    {  
        ll price = 0;
        ll u = qe.front(); 
        qe.pop();
        for(auto v:graph[u])
        {
            if(v!=graph[u][0])
                price=1;
            if(Count[v]<=Count[u]+price)
                continue;
            else
            {
                Count[v] = Count[u]+price;
                qe.push(v);
            }
        }
    }
}
int main()
{
    ll n,s,e;
    cin>>n>>s>>e;
    vector<vector<ll>> graph(n+1);
    vector<ll> Count(n+1,LLONG_MAX);
    Count[s] = 0;
    for(ll i = 1;i<=n;i++)
    {
        ll num;
        cin>>num;
        while(num--)
        {
            ll temp;
            cin>>temp;
            graph[i].push_back(temp);
        }
    }
    // for(ll i = 1;i<=n;i++)
    // {
    //     cout<<i<<"的邻接点 = ";
    //     for(auto j:graph[i])
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
    BFS(graph,s,e,Count);
    if(Count[e]==LLONG_MAX)
        cout<<-1<<endl;
    else
        cout<<Count[e]<<endl;
    return 0;
}