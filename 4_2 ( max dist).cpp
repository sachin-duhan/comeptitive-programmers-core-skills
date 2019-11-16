#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
using namespace std;
ll cnt[200001],cnt1[200001];
int main()
{
    fast;
    ll t;
    cin>>t;
    ll l=INT_MAX,h=INT_MIN,le=INT_MAX,he=INT_MIN;
    for(ll i=0;i<t;i++)
    {
        ll a;
        cin>>a;
        if(a>he)
        {
            he=a;
            h=i+1;
        }
        if(a<le)
        {
            le=a;
            l=i+1;
        }
        cout<<h<<" "<<l<<endl;
    }
    return 0;
}
