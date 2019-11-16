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
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    V<V<int>> dp(n+1,V<int> (m+1,0));
    int in,d,s;
    cin >> in >> d >> s;
    loop(i,0,n+1){
        loop(j,0,m+1){
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }else if(i == 0){
                dp[i][j] = dp[i][j-1] + in;
            }else if(j == 0){
                dp[i][j] = dp[i-1][j] + d;
            }
            else if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(dp[i-1][j-1]+s,min(dp[i-1][j]+d,dp[i][j-1]+in));
            }
        }
    }
    //UNCOMMENT THIS TO SEE WHOLE DP MATRIX
    // cout << "           ";
    // loop(i,0,m)printf("%5c ",b[i]);
    // cout << "\n";
    // loop(i,0,n+1){
    //     if(i == 0)cout << "      ";
    //     else printf("%5c ",a[i-1]);
    //     loop(j,0,m+1){
    //         printf("%5d ",dp[i][j]);
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][m];
  return 0;
}
