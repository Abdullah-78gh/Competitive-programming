#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> coin(n+1);
    for (int i = 1; i <= n; i++)cin >> coin[i];
 
    bool dp[n+1][k+1][k+1] = {};
    dp[0][0][0] = 1;
 
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            for (int kk = 0; kk <= k; kk++){
                if (dp[i-1][j][kk] == 1)dp[i][j][kk] = 1;
 
                if (coin[i] <= j && coin[i] <= kk && dp[i-1][j - coin[i]][kk - coin[i]] == 1){
                    dp[i][j][kk] = 1;
                }
 
                if (coin[i] <= j && dp[i-1][j - coin[i]][kk] == 1){
                    dp[i][j][kk] = 1;
                }
            }
        }
    }
 
    set<int> ans;
    for (int i = 0; i <= k; i++){
        if (dp[n][k][i] == 1)ans.insert(i);
    }
    cout << ans.size() << endl;
    for (auto x: ans)cout << x << " ";cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}