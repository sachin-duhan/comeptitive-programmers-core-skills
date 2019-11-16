#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a*b<0)
        cout<<a/b;
    else
    {
        if(a%b==0)
            cout<<a/b;
        else
            cout<<a/b+1;
    }
}
