#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll tm = min(a, x); a -= tm; x -= tm;
    tm = min(b, y); b -= tm; y -= tm;
    cout << (c >= x+y?"YES\n":"NO\n");
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}