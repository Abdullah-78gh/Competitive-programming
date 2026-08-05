#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll a, b; cin >> a >> b;
    ll c = 1, rem = (1ll<<a) - 1, ans = 0;
 
    while(rem){
        ans++;
        rem -= min(c, rem);
        c = min(c*2, b);
 
        if (c == b){
            cout << (rem + c - 1)/c + ans << endl; 
            return;
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}