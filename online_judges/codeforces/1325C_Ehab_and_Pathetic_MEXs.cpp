#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n;  cin >> n;
    vector< vector<int> > g(n+1);
    vector<pair<int, int> >e;
 
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back({u, v});
    }
 
    vector<int> ans(n-1);
    int mn = 0, mx = n-2;
    for (int i = 0; i < n-1; i++){
        int u = e[i].first;
        int v = e[i].second;
 
        if (g[u].size() == 1 || g[v].size() == 1){
            ans[i] = mn++;
        }
        else ans[i] = mx--;
    }
    for (auto x: ans)cout << x << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}