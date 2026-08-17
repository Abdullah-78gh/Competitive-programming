#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void dfs(int n, int p, bool &ok, vector< vector<int> > &g, vector<int> &d){
    if (d[n]){
        if (ok)ok = 0;
        else cout << n << " ";
    }
    for (auto x: g[n]){
        if (x == p)continue;
        dfs(x, n, ok, g, d);
    }
}
 
void solve() {
    int n; cin >> n;
    vector< vector<int> > g(n+1);
 
    for (int i = 2; i <= n; i++){
        int v; cin >> v;
        g[i].push_back(v);
        g[v].push_back(i);
    }
 
    int m; cin >> m;
    vector<int> d(n+1, 0);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        d[x] = 1;
    }
 
    if (m == 1){cout << 0 << endl; return;}
 
    cout << m-1 << " ";
    bool ok = 1;
    dfs(1, -1, ok, g, d);
    cout << endl;
 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}