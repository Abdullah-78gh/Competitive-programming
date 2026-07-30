#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
 
    vector<ll> v(n);
    for (auto &x: v)cin >> x;
    if (n == 1){cout << v[0] << endl;return;}
 
    bool p = 0, ng = 0;
    ll ans = 0, mn = 1e18;
    for (int i = 0; i < n; i++){
        if (v[i] <= 0)ng = 1;
        else if (v[i] >= 0)p = 1;
        ans += abs(v[i]);
        mn = min(mn, abs(v[i]));
    }
    if (p & ng)cout << ans << endl;
    else cout << ans - 2*mn << endl;
 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}