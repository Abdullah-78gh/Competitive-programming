#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n;
 
    ll c = 0;
    for (ll i = 1; i <= n; i++){
        c += (n/i) * (n/i);
    }
 
    cout << c << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}