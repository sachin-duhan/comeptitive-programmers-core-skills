#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;

int main(){
    int n;
    cin >> n;
    V<int> a(n+1);
    V<int> b(n+1);
    loop(i,1,n+1)cin >> a[i];
    loop(i,1,n+1)cin >> b[i];
    V<V<int> > dp(n+1,V<int>(n+1,0));
    V<V<bool> > ddp(n+1,V<bool>(n+1,false));
    loop(i,1,n+1){
        loop(j,1,n+1){
            if(a[i] == b[j]){dp[i][j] = dp[i-1][j-1]+1;ddp[i][j]=true;}
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    // loop(i,0,n+1){
    //     loop(j,0,n+1){
    //         printf("%5d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int i = n;
    int j = n;
    V<int> x,y;
    while(i && j){
        if(ddp[i][j]){
            x.pb(i);
            y.pb(j);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    cout << x.size() << "\n";
    for(auto &i: x)cout << i-1 << " ";
    cout << "\n";
    for(auto &i: y)cout << i-1 << " ";
  return 0;
}
