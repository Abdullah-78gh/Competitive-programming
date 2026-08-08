#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n, m; cin >> n >> m;
 
    ll a; cin >> a;
    ll gc = 0;
    for (ll i = 1; i < n; i++){
        ll x; cin >> x;
        gc = __gcd(gc, abs(a - x));
    }
    for (ll i = 0; i < m; i++){
        ll x; cin >> x;
        cout << __gcd(gc, a+x) << " \n"[i == m-1];
    }
    
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // ll t; cin >> t; while(t--)
    solve();
}