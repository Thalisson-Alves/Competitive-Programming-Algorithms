// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
#define mp make_pair

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void run(){
  int n; cin >> n;
  vector<pii> xs(n);
  // [ending, beggining]
  for(int i =0 ; i < n; ++i) {
    cin >> xs[i].second >> xs[i].first;
  }
  sort(all(xs));

  int ans = 1;
  int l = 0;
  int r = 1;
  while(r < n) {
    if(xs[r].second < xs[l].first) r++;
    else {
      ans ++;
      l = r;
      r++;
    }
  }
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, sorting and searching, greedy.
