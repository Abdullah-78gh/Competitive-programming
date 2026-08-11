#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
pair<int, int> dfs(int node, int par, string &s, vector<vector<int> >&g, int &ans){
    int w = 0, b = 0;
    for (auto x: g[node]){
        if (x == par)continue;
        auto tm = dfs(x, node, s, g, ans);
        w += tm.first;
        b += tm.second;
    }
    s[node] == 'W'?w++:b++;
    ans += w == b;
    return make_pair(w, b);
}
 
void solve() {
    int n; cin >> n;
    vector<vector<int> > g(n+1, vector<int>());
 
    for (int u = 2; u <= n; u++){
        int v; cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s; cin >> s;
    s = "#" + s;
 
    int ans = 0;
    auto x = dfs(1, -1, s, g, ans);
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}