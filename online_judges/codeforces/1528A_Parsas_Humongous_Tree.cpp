#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
 
ll dp[N][2];
 
void dfs(ll node, ll p, vector< vector<ll> > &g, vector<ll> &l, vector<ll> &r){
    dp[node][0] = dp[node][1] = 0;
    for (auto x: g[node]){
        if (x == p)continue;
        dfs(x, node, g, l, r);
        dp[node][0] += max(dp[x][0] + abs(l[x] - l[node]), dp[x][1] + abs(r[x] - l[node]));
        dp[node][1] += max(dp[x][0] + abs(l[x] - r[node]), dp[x][1] + abs(r[x] - r[node]));
    }
}
 
void solve() {
    ll n; cin >> n;
 
    vector< vector<ll> > g(n+1);
    vector<ll> l(n+1), r(n+1);
 
    for (ll i = 1; i <= n; i++) cin >> l[i] >> r[i];
 
    for (ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, -1, g, l, r);
    cout << max(dp[1][0], dp[1][1]) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}