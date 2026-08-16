#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void dfs(int n, int c, int &ans, vector<vector<pair<int,int>>> &v){
    // cout << n << endl;
    for (auto x: v[n]){
        dfs(x.first, c+x.second, ans, v);
    }
    // if (n == 3)cout << c << endl;
    if (v[n].empty())ans = min(ans, c);
}
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    vector<vector<pair<int,int> > > v(n+1);
 
    for (int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        if (l){
            int w = (s[i-1] == 'L'?0:1);
            v[i].push_back({l, w});
        }
        if (r){
            int w = (s[i-1] == 'R'?0:1);
            v[i].push_back({r, w});
        }
    }
 
    int ans = 1e9;
    dfs(1, 0, ans, v);
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}