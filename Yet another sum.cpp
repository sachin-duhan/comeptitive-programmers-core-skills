#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll n;
    cin>>n;
    double sum1=0,sum2=0;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        sum1+=x;
        sum2+=(double)1/x;
    }
    cout<<fixed<<setprecision(9)<<sum1+sum2;
}
