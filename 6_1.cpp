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
    int n,W;
    cin >> n >> W;
    int val[110],w[110],dp[110][1010];
    loop(i,1,n+1)cin >> w[i] >> val[i];
    memset(dp,0,sizeof(dp));
    loop(i,1,n+1){
        loop(j,1,W+1){
            if(w[i] > j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+val[i]);
        }
    }
    // loop(i,0,n+1){
    //     loop(j,0,W+1){
    //         printf("%3d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // cout << dp[n][W];
    set<int> c;
    int i = n;
    int j = W;
    while(i){
        if(dp[i-1][j] != dp[i][j]){
            c.insert(i);
            j -= w[i];
        }
        i--;
    }
    cout << c.size() << "\n";
    for(auto &i: c)cout << i << " ";
  return 0;
}
