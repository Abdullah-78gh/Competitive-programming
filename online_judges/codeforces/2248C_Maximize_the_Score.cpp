#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n; n *= 2;
    vector<ll> v(n), last(n, -1), dp(n, 0);
 
    for (auto &x: v) cin >> x;
 
    for (int i = 0; i < n; i++){
        ll pv = i?dp[i-1]:0;
        dp[i] = 1 + pv;
        if (last[v[i]] == -1)last[v[i]] = i;
        else {
            pv = last[v[i]] - 1 >= 0?dp[last[v[i]] - 1] : 0;
            ll len = i - last[v[i]] + 1;
            dp[i] = max(dp[i], pv + len*len);
        }
    }
    cout << dp[n-1] << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}