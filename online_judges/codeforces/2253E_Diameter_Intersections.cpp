#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+2;
 
int bfs(int nd, vector<vector<int> >&g, vector<int> &d ){
    queue<int> q;
    q.push(nd);
    bool vis[(int)d.size()] = {};
    vis[nd] = 1;
    int ans = nd, mx = 0;
 
    while(!q.empty()){
        int node = q.front(); q.pop();
 
        for (auto x: g[node]){
            if (vis[x] == 0){
                vis[x] = 1;
                d[x] = d[node] + 1;
                if (d[x] > mx)mx = d[x], ans = x;
                q.push(x);
            }
        }
    }
    return ans;
}
 
int dfs(int node, int par, int dep, vector<vector<int> >&g, set<int> &s, int need){
    int cnt = 0, mx = 0;
    for (auto x: g[node]){
        if (x == par)continue;
 
        int tm = dfs(x, node, dep+1, g, s, need);
 
        if (dep + tm == need)cnt++;
        mx = max(mx, tm);
    }
    if (cnt >= 2)s.insert(dep);
    return mx+1;
}
 
void solve() {
    int n; cin >> n;
    vector<vector<int> > g(n+1, vector<int>());
 
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    vector<int> da(n+1, 0), db(n+1 ,0);
 
    int a = bfs(1, g, da);
    da[a] = 0;
    int b = bfs(a, g, da);
    int c = bfs(b, g, db);
 
    // for (auto x: da)cout << x << " "; cout << endl;
    // for (auto x: db)cout << x << " "; cout << endl;
    // cout <<a  << " " << b << endl;
 
    int dia = *max_element(da.begin(), da.end());
 
    for (int i = 1; i <= n; i++){
        if (da[i] == dia/2 && db[i] == (dia+1)/2)a = i;
        else if (da[i] == (dia+1)/2 && db[i] == dia/2)b = i;
    }
 
    // cout << a << " " << b << endl;
 
    set<int> s1, s2, ans;
 
    int tm = dfs(a, b, 0, g, s1, dia/2);
    int tm2 = dfs(b, a, 0, g, s2, dia/2);
 
    s1.insert(dia/2);
    s2.insert(dia/2);
    ans.insert(dia);
    
    for (auto x: s1){
        for (auto y: s2){
            ans.insert(x+y+1);
        }
    }
 
    cout << ans.size() << " ";
    for (auto x: ans)cout << x << " ";
    cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}