
// 洛谷 P4017 最大食物链计数

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 80112002;

ll Solve(vector<vector<ll>>& graph, vector<ll>& memo, ll u)
{
    if(memo[u] != -1) return memo[u];        
    ll res = 0;
    for(auto v : graph[u])
        res = (res + Solve(graph, memo, v)) % MOD;  
    if(graph[u].empty()) res = 1;           
    return memo[u] = res;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> graph(n+1);           
    vector<ll> memo(n+1, -1);                
    vector<ll> indeg(n+1, 0);
    for(ll i = 0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;                           
        graph[a].push_back(b);
        indeg[b]++;
    }
    ll ans = 0;
    for(ll i = 1;i<=n;i++)
        if(indeg[i]==0)                     
            ans = (ans + Solve(graph, memo, i)) % MOD;  
    cout<<ans<<endl;
    return 0;
}
