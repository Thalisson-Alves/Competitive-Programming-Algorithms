enum class state { not_visited, processing, done };
bool dfs(const vector<vll> &adj, ll s, vector<state> &states, vll &order) {
  states[s] = state::processing;
  for (auto &v : adj[s]) {
    if (states[v] == state::not_visited) {
      if (not dfs(adj, v, states, order)) return false;
    } else if (states[v] == state::processing)
      return false;
  }
  states[s] = state::done;
  order.pb(s);
  return true;
}
vll topologicalSorting(const vector<vll> &adj) {
  ll n = len(adj);
  vll order;
  vector<state> states(n, state::not_visited);
  for (int i = 0; i < n; ++i) {
    if (states[i] == state::not_visited) {
      if (not dfs(adj, i, states, order)) return {};
    }
  }
  reverse(all(order));
  return order;
}
