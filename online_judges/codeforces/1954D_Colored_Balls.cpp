#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x: v)cin >> x;
 
    int s = accumulate(v.begin(), v.end(), 0ll);
    vector<ll> dp(s+1);
 
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = s - v[i]; j>= 0; j--){
            dp[j+v[i]] = (dp[j+v[i]] + dp[j]) % mod;;
        }
    }
 
    int ans = 0;
    for (int j = 1; j <= s; j++){
        ans = (ans + (1ll * (j+1)/2 * dp[j])%mod) %mod;
    }
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < v[i]; j++){
            ans = (ans + 1ll * (v[i] - (v[i]+j+1) / 2) * dp[j]) % mod;
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}