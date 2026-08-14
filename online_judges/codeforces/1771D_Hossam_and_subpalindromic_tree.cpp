#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;
 
string s;
int dp[N][N];
int nxt[N][N];
 
vector<int> vs;
void dfs(int node, int p, vector< vector<int> > &g){
    vs.push_back(node);
    for (auto x: g[node]){
        if (x != p)dfs(x, node, g);
    }
}
 
int fun(int l, int r){
    if (l == r)return 1;
    int &ans = dp[l][r];
    if (ans != -1)return ans;
    ans = 0;
    if (s[l] == s[r]){
        ans = 2 + (nxt[l][r] == r ? 0 : fun(nxt[l][r], nxt[r][l]) );
    }
    else {
        ans = max(fun(nxt[l][r], r), fun(l, nxt[r][l]));
    }
    if (!ans)ans = 1;
    return ans;
}
 
void solve() {
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    cin >> s;
    s = "0" + s;
    vector< vector<int> >g(n+1);
    if (n == 1){cout << 1 << endl; return;}
 
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
 
    for (int i = 1; i <= n; i++){
        for (auto x: g[i]){
            vs.clear();
            dfs(x, i, g);
            for(auto it: vs){
                nxt[i][it] = x;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if ((int)g[i].size() == 1 && (int)g[j].size() == 1){
                ans = max(ans, fun(i, j));
            }
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}