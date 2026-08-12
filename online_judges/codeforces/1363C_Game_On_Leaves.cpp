#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, k; cin >> n >> k;
    
    vector< vector<int> >g(n+1);
 
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    if (g[k].size() <= 1){cout << "Ayush\n"; return;}
 
    queue<int> q;
    bool  vis[n+1] = {};
    vis[k] = 1;
    q.push(k);
    int c = 0;
 
    while (!q.empty()){
        int node = q.front(); q.pop();
 
        for (auto x: g[node]){
            if (!vis[x]){
                vis[x] = 1;
                q.push(x);
                c++;
            }
        }
    }
 
    if (c&1)cout << "Ayush\n";
    else cout << "Ashish\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}