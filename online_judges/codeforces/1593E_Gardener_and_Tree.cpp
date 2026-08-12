#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, k; cin >> n >> k;
 
    if (n == 1){cout << 0 << endl; return;}
 
    vector< vector<int> > g(n+1);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    queue<int> q;
    vector<int> dis(n+1), cnt(n+1, 0), rem(n+1, 0);
    bool vis[n+1] = {};
    for (int i = 1; i <= n; i++){
        cnt[i] = g[i].size();
        if (g[i].size() == 1){
            q.push(i);
            dis[i] = 1;
            vis[i] = 1;
            rem[1]++;
        }
    }
 
    while (!q.empty()){
        int node = q.front(); q.pop();
 
        for (auto x: g[node]){
            cnt[x] --;
            if (cnt[x] == 1 && !vis[x]){
                vis[x] = 1;
                dis[x] = dis[node] + 1;
                rem[dis[x]]++;
                q.push(x);
            }
        }
    }
 
    int ans = n;
    for (int i = 1; i <= n; i++){
        ans -= rem[i];
        if (i == k){cout << ans << endl; return;}
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}