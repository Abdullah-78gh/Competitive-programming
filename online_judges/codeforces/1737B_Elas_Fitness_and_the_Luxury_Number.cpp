#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll fun(ll x){
    ll sq = 0, hi = 1e9, lo = 0;
    while(lo <= hi){
        ll m = (lo+hi)/2;
        if (m*m <= x){sq = max(sq, m); lo = m+1;}
        else hi = m-1;
    }
    ll ans = (sq-1)*3 + 1;
    if (sq*sq + sq <= x)ans++;
    if (sq*sq + 2*sq <= x)ans++;
    return ans;
}
 
void solve() {
    ll l, r; cin >> l >> r;
    cout << fun(r) - fun(l - 1) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}