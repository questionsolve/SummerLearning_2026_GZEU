
// 洛谷 P17218 [ICPC 2017 Nanning R] The Game of Life

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll T;
    cin>>T;
    while(T--)
    {   
        set<pair<ll,ll>> life;
        ll n,m;
        ll max_num = 0,max_generation = 0, num_321 = 0;
        cin>>n>>m;
        for(int i = 0 ;i<n;i++)
        {             
               cin.ignore();
            for(int j = 0;j<m;j++)
            {
                char c;
                c = cin.get();
                if(c=='#'){
                    life.emplace(i,j);
                    // cout<<i<<" "<<j<<"  "<<endl;
                    max_num++;
                }
            }
        }
        for(int m = 1;m<=321;m++)
        {
            map<pair<ll,ll>,ll> neighbor;
            ll num = 0;
            set<pair<ll,ll>> new_life;
                for(auto &ele: life)
            {
                for(int i = -1;i<=1;i++)
                {
                    for(int j = -1;j<=1;j++)
                    {
                        if(i ==0&&j == 0)
                            continue;
                    ll x = ele.first+i;
                    ll y = ele.second+j;
                    neighbor[{x,y}]++;
                    //    cout<<"neighbor["<<x<<" ,"<<y<<"]= "<<neighbor[{x,y}]<<endl;
                    }
                }
            }
            for(auto &[key,value] : neighbor)
            {
                if(value == 3)
                {
                     new_life.emplace(key);
                    //  cout<<"存活细胞位置"<<key.first<<" "<<key.second<<endl;
                     num++;
                }
                else if(value == 2 && life.find(key)!=life.end())
                 {
                        new_life.emplace(key);
                        //  cout<<"存活细胞位置"<<key.first<<" "<<key.second<<endl; 
                        num++;
                }
               else
                    continue;
            }
            if(num>max_num)
                {
                    max_num = num;
                    max_generation = m;
                }
            if(m == 321)
                num_321 = num;
            life = new_life;
        }

        cout<<max_generation<<" "<<max_num<<" "<<num_321<<endl;
        
    }
    return 0;
}