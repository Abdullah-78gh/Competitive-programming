#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, k; cin >> n >> k;
    int ans = -2e9;
    while(n--){
        int f, t; cin >> f >>  t;
        if (t > k)ans = max(ans, f - (t - k));
        else ans = max(ans, f);
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}