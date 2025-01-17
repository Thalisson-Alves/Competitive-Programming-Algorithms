#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll INF = 1e18;

void run() {
  int n;
  cin >> n;

  vi xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];

  ll ans, qtd0, qtd1;
  ans = qtd0 = qtd1 = 0;
  for (int i = n - 1; i >= 0; i--) {
    int k = xs[i];
    if (k) {
      ll q1 = qtd1;
      qtd1 = qtd0 + 1ll;
      qtd0 = q1;
    } else
      qtd0++;

    ans += qtd1;
  }

  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, ad-hoc, dp
