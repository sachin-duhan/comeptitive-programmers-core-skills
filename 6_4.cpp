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
    int n,m,k;
    cin >> n >> k;
    m = n;
    V<V<int>> arr(n+1,V<int>(m+1,0));
    V<V<int>> dp(n+1,V<int>(m+1,0));
    loop(i,1,n+1){
        loop(j,1,m+1)cin >> arr[i][j];
    }
    loop(i,1,n+1){
        loop(j,1,m+1)dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }
    int ans = 0;
    loop(i,1,n+1){
        int i1 = i+k-1;
        if(i1 > n)break;
        loop(j,1,m+1){
            int j1 = j+k-1;
            if(j1 > m)break;
            ans = max(ans,dp[i1][j1] - dp[i-1][j1] - dp[i1][j-1] + dp[i-1][j-1]);
        }
    }
    cout << ans;
  return 0;
}
