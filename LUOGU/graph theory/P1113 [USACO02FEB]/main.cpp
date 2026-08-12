
// 洛谷 P1113 [USACO02FEB] 杂务

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<ll> time(n+1);
    for(ll i = 1;i<=n;i++)
    {
        ll num,t,temp;
        vector<ll> before;
        cin>>num>>t;
        while(cin>>temp&&temp!=0)
            before.push_back(temp);
        if(before.size()!=0)
        {
             ll Time = -1;
            for(ll j = 0;j<before.size();j++)
            {
                if(Time<time[before[j]])
                    Time = time[before[j]];
            }
            t += Time;
        }
        time[i] = t;
    }
    ll ans = 0;
    for(ll i = 1;i<=n;i++)
        ans = max(ans,time[i]);
    cout<<ans<<endl;
    return 0;   
}