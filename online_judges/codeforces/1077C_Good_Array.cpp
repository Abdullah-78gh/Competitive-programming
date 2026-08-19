#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
 
    for (auto &x: v)cin >> x;
    vector tm = v;
    unordered_set<ll> good;
    sort(tm.begin(), tm.end());
 
    ll mx = tm[n-1], mx2 = tm[n-2], s = accumulate(tm.begin(), tm.end(), 0ll);
 
    for (ll i = 0; i < n; i++){
        ll ts = s - tm[i];
        ll tmx = tm[n-1];
        if (i == n-1)tmx = tm[n-2];
 
        if (ts == 2*tmx)good.insert(tm[i]);
    }
 
    vector<ll> ans;
    for (ll i = 0; i < n; i++){
        if (good.count(v[i]))ans.push_back(i+1);
    }
 
    cout << ans.size() << endl;
    for (auto x: ans)cout << x<< " ";
    cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // ll t; cin >> t; while(t--)
    solve();
}