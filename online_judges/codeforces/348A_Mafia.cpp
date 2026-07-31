#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto &x: v) cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0ll);
    ll mx = *max_element(v.begin(), v.end());
    cout << max((sum / (n-1) + (sum % (n-1) > 0)), mx) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}