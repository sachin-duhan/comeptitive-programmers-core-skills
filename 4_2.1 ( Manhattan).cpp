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
bool c1(pair<int,PII> a, pair<int,PII> b){
    int s1 = a.S.F + a.S.S;
    int s2 = b.S.F + b.S.S;
    return s2 > s1;
}
bool c2(pair<int,PII> a, pair<int,PII> b){
    int s1 = a.S.F - a.S.S;
    int s2 = b.S.F - b.S.S;
    return s2 > s1;
}
bool c3(pair<int,PII> a, pair<int,PII> b){
    int s1 = -a.S.F + a.S.S;
    int s2 = -b.S.F + b.S.S;
    return s2 > s1;
}
bool c4(pair<int,PII> a, pair<int,PII> b){
    int s1 = -a.S.F - a.S.S;
    int s2 = -b.S.F - b.S.S;
    return s2 > s1;
}

int manhattan(pair<int,PII> a, pair<int,PII> b){
    return abs(a.S.F-b.S.F) + abs(a.S.S-b.S.S);
}

int main(){
  priority_queue<pair<int,PII>,V<pair<int,PII> >,function<bool(pair<int,PII>,pair<int,PII>)> > p1(c1);
  priority_queue<pair<int,PII>,V<pair<int,PII> >,function<bool(pair<int,PII>,pair<int,PII>)> > p2(c2);
  priority_queue<pair<int,PII>,V<pair<int,PII> >,function<bool(pair<int,PII>,pair<int,PII>)> > p3(c3);
  priority_queue<pair<int,PII>,V<pair<int,PII> >,function<bool(pair<int,PII>,pair<int,PII>)> > p4(c4);
  ll prev_ans = -inf;
  PII prev = mp(0,0);
  int n;
  cin >> n;
  loop(i,1,n+1){
      pair<int,PII> a;
      cin >> a.S.F >> a.S.S;
      a.F = i;
      p1.push(a);
      p2.push(a);
      p4.push(a);
      p3.push(a);
      if(prev_ans < manhattan(p1.top(),a)){
          prev_ans = manhattan(p1.top(),a);
          prev = mp(a.F,p1.top().F);
      }
      if(prev_ans < manhattan(p2.top(),a)){
          prev_ans = manhattan(p2.top(),a);
          prev = mp(a.F,p2.top().F);
      }
      if(prev_ans < manhattan(p3.top(),a)){
          prev_ans = manhattan(p3.top(),a);
          prev = mp(a.F,p3.top().F);
      }
      if(prev_ans < manhattan(p4.top(),a)){
          prev_ans = manhattan(p4.top(),a);
          prev = mp(a.F,p4.top().F);
      }
      cout << prev.F << " " << prev.S << "\n";
  }
  return 0;
}
