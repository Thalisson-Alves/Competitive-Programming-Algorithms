// iagorrr ;)
#include <bits/stdc++.h>
#include <climits>
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

struct SegmentTree {
  int N;
  vll ns, lazy;
  SegmentTree(const vll &xs): N(xs.size()), ns(4 * N, INT_MAX), lazy(4 * N, 0) {
    for (size_t i = 0; i < xs.size(); ++i)
      update(i, i, xs[i]);
  }
  void update(int a, int b, ll value) { update(1, 0, N - 1, a, b, value); }
  void update(int node, int L, int R, int a, int b, ll value) {
    if (lazy[node]){
      ns[node] = ns[node] == INT_MAX ? lazy[node] : ns[node] + lazy[node];
      if (L < R) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (a > R or b < L) return;
    if (a <= L and R <= b) {
      ns[node] = ns[node] == INT_MAX ? value : ns[node] + value;
      if (L < R){
        lazy[2 * node] += value;
        lazy[2 * node + 1] += value;
      }
      return;
    }
    update(2 * node, L, (L + R) / 2, a, b, value);
    update(2 * node + 1, (L + R) / 2 + 1, R, a, b, value);
    ns[node] = min(ns[2 * node], ns[2 * node + 1]);
  }
  ll RMQ(int a, int b) { return RMQ(1, 0, N - 1, a, b); }
  ll RMQ(int node, int L, int R, int a, int b) {
    if (lazy[node]) {
      ns[node] = ns[node] == INT_MAX ? lazy[node] : ns[node] + lazy[node];
      if (L < R) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (a > R or b < L) return INT_MAX;

    if (a <= L and R <= b) return ns[node];
    ll x = RMQ(2 * node, L, (L + R) / 2, a, b);
    ll y = RMQ(2 * node + 1, (L + R) / 2 + 1, R, a, b);
    return min(x, y);
  }
};

void run(){
  ll n, m; cin >> n >> m;
  vll h(n); INV(h);
  vll t(m); INV(t);

  SegmentTree st(vector<ll>(1e9+1));
  for(int i = 0; i < n; ++i) {
    st.update(h[i], h[i], i+1);
  }
  
  cerr << "startin queries\n";
  for(int i = 0; i < m; ++i) {
    int pos = st.RMQ(t[i], 1e9);
    if(pos != INT_MAX) {
      cout << pos << ' '; 
      st.update(h[pos-1], h[pos-1], -t[i]);
      h[pos-1] -= t[i];
    }
    else {
      cout << 0 << ' ' << '\n';
    }
  }
}
int32_t main(void){ // fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

