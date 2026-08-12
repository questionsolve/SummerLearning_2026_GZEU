//2026牛客暑期多校训练营8 H--It's Magic, Not a Trick!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;
ll Solve(vector<ll> &v, ll x, __int128 count_in ){
        ll ans = 0;
        ll left = 0,right = v.size()-1;
        while(left<=right){
                ll it = v[left];
                ll temp = x-it;
                if(count_in+1>=temp){
                    left++;
                    count_in = count_in-temp<0?0:count_in-temp+1;
                }
                else
                     break;
        }
        count_in%=(x-1);
        ans=(ans + (ll)(count_in % MOD))%MOD;
        while(left<=right){
            if(v[left] == 0)
                break;
            ans=(ans+v[left])%MOD;
            left++;
        }
        return ans%MOD;
        
}
int main(){
    ll T;
    cin>> T;
    while(T--){
        ll n,x;
        cin>>n>>x;
        vector<ll> v(n);
        __int128 count_in = 0;
        if(x == 1)
        {
            ll ans = 0;
            for(ll i = 0;i<n;i++){
                ll temp;
                cin>>temp;
                ans+=temp;
                ans%=MOD;
            }
            cout<<ans<<endl;
            continue;
        }
        for(ll i=0;i<n;i++){
           ll temp;
           cin>>temp;
           if(temp>=x){
               count_in += temp/x;
               temp = temp%x;
           }
           v[i] = temp;
    }
        sort(v.begin(),v.end(),greater<ll>());
            cout<<Solve(v,x,count_in)<<endl;
    }
    return 0 ;
}