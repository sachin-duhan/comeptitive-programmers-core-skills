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
const ll inf = 1e9;
int main(){
  int n;
  cin >> n;
  V<PLL> arr(n+1);
  cin >> arr[1].F;
  loop(i,2,n+1){
    cin >> arr[i-1].S;
    arr[i].F = arr[i-1].S;
  }
  cin >> arr[n].S;
  // loop(i,1,n+1){
  //   printf("(%lld x %lld)\t",arr[i].F,arr[i].S);
  // }
  // printf("\n");
  // ll dp[200][200];
  // memset(dp,inf,sizeof(dp));
  V<V<ll>> dp(200,V<ll>(200,inf));
  loop(i,0,200)dp[i][i] = 0;
  // loop(i,0,n+1){
  //   loop(j,0,n+1){
  //     if(dp[i][j] == inf)printf("  inf ");
  //     else printf("%5lld ",dp[i][j]);
  //   }
  //   printf("\n");
  // }
  for(int size = 2; size <= n; ++size){
    for(int i = 1; i <= n; ++i){
      int j = i+size-1;
      // cout << j << endl;
      if(j > n)break;
      // printf("FOR %d -- %d\n",i,j);
      for(int k = i; k < j; ++k){
        // printf("SET = {(%d,%d)(%d,%d)}  ",i,k,k+1,j);
        dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + (arr[i].F * arr[k].S * arr[j].S));
      }
      // printf("\n");
    }
  }
  // loop(i,0,n+1){
  //   loop(j,0,n+1){
  //     if(dp[i][j] == inf)printf("  inf ");
  //     else printf("%5lld ",dp[i][j]);
  //   }
  //   printf("\n");
  // }
  cout << dp[1][n];
  return 0;
}
