#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll sum1=0,sum2=0;
    for(ll i=0;i<n;i++)
    {
        double a;
        cin>>a;
        a*=1000;
        sum1+=a;
    }
    for(ll i=0;i<n;i++)
    {
        double a;
        cin>>a;
        a*=1000;
        sum2+=a;
    }
    if(sum1==sum2)
        cout<<"SUM(A)=SUM(B)";
    else if(sum1>sum2)
        cout<<"SUM(A)>SUM(B)";
    else
        cout<<"SUM(A)<SUM(B)";
}
