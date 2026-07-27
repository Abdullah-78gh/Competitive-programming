#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (auto &x: v) cin >> x;
    for (int i = 0; i < n; i++)v[i] = (v[i] > 0?1:-1);
 
    ll c = 1, pos = 0, neg = 0, ans = 0;
    for (int i = 0; i < n; i++){
        c *= v[i];
        if (c > 0)ans += ++pos;
        else ans += neg++;
    }
    cout << (n*(n+1))/2 - ans << " " << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}