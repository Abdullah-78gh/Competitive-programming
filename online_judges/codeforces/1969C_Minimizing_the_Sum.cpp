#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
 
void solve() {
    int n, k; cin >> n >> k;
    vector<ll> v(n+1);
    for (int i = 0; i < n; i++)cin >> v[i+1];
 
    ll dp[n+1][k+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++)dp[i][j] = INF;
    }
    dp[0][0] = 0;
 
    for (int i = 1; i <= n; i++){
        for (int kk = 0; kk <= k; kk++){
            if (i < kk+1)continue;
            for (int j = 0; j <= kk; j++){
                ll mn = 1e18;
                for (int it = 0; it <= j; it++){
                    mn = min(mn, v[i - it]);
                }
                mn *= (j+1);
                dp[i][kk] = min(dp[i][kk], dp[i-(j+1)][kk - j] + mn);
            }
        }
    }
 
    // for (int i = 1; i<= n; i++){
    //     for (int j = 0; j <= k; j++)cout << dp[i][k];
    // }
 
    ll ans = INF;
    for (int i = 0; i <= k; i++)ans = min(ans, dp[n][i]);
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}