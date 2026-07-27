#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
 
ll dp[2001][2001];  // k- remaining // m - multiple
 
ll fun(ll n, ll k, ll m){
    if (dp[k][m] != -1)return dp[k][m];
    if (k <= 0)return 1;
 
    dp[k][m] = 0;
    for (int j = m; j <= n; j += m){
        dp[k][m] = (dp[k][m] + fun(n, k-1, j) )% mod;
    }
    return dp[k][m];
}
 
void solve() {
    memset(dp, -1, sizeof(dp));
    ll n, k; cin >> n >> k;
    cout << fun(n, k, 1) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}