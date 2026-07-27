#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    ll c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++){
        ll x; cin >> x; 
        if (x == 0)c0++;
        if (x == 1)c1++;
    }
    cout << (1ll<<c0) * c1 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}