#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
 
    for (auto &x: a)cin >> x;
    for (auto &x: b)cin >> x;
 
    ll sa = 0, sb = 0;
    for (ll i = 0; i < a.size(); i++){
        if (i+1 == a.size())sa += a[i];
        else sa += a[i] - a[i+1] + 1;
    }
    for (ll i = 0; i < b.size(); i++){
        if (i+1 == b.size())sb += b[i];
        else sb += b[i] - b[i+1] + 1;
    }
    if (sb <= sa)cout << 1 << endl;
    else cout << 2 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}