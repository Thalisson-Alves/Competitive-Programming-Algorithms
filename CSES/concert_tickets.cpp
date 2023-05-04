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
  int n, m; cin >> n >> m;

  multiset<int> st;
  for(int i = 0; i < n; ++i){
    int x; cin >> x;
    st.insert(x);
  }
  vi b(m); for(int i = 0; i < m; ++i){ cin >> b[i]; }

  vi ans(m, -1);
  for(int i = 0; i < m; ++i) {
    if(st.empty()) break;
    auto closer = st.upper_bound(b[i]);
    if(closer != st.begin()) closer = prev(closer);
    if(*closer <= b[i]) {
      ans[i] = *closer;
      st.erase(closer);
    }
  }
  for(auto c : ans) cout << c << '\n';
}
int32_t main(void){ //fastio;

  int t; t = 1;
  
  while(t--)
    run();
}

// AC, searching and sorting, multiset
