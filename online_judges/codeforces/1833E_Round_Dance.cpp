#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
 
    vector<int> con(n+1, 0);
    vector< set<int> > g(n+1);
 
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        g[x].insert(i);
        g[i].insert(x);
    }
 
    int cc = 0, connect = 0;
    bool vis[n+1] = {};
    for (int i = 1; i < n; i++){
        if (!vis[i]){
            cc ++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            bool ok = 0;
 
            while(!q.empty()){
                int node = q.front(); q.pop();
                if (g[node].size() == 1)ok = 1;
 
                for (auto x: g[node]){
                    if (!vis[x]){
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
            connect += ok;
        }
    }
 
    cout << cc - connect + (connect > 0) << " " << cc << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}