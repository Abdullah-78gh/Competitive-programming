#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool v[10000];
bool cycle = 0;
int cnt = 0;
 
void dfs(int n,int p,  vector<vector<int> > &g){
    v[n] = 1;
    cnt++;
    for (auto x: g[n]){
        if (x == p)continue;
        if (v[x])cycle = 1;
        else dfs(x, n, g);
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int> >g(n+1);
 
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    memset(v, 0, sizeof v);
    dfs(1, -1, g);
 
    if (!cycle && cnt == n)cout << "yes\n";
    else cout << "no\n";
 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}