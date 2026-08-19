#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n+1, 0), dp(n+1, 0);
    for (int i = 1; i <= n; i++)cin >> v[i];
    unordered_map<int,int> last;
    int mx = 0, mxv = 0;
 
    for (int i = 1; i <= n; i++){
        last[v[i]] = i;
        int idx = last[v[i] - 1];
 
        if (idx == 0){
            dp[i] = 1;
        }
        else {
            dp[i] = dp[idx]+1;
        }
        if (dp[i] > mx){
            mx = dp[i];
            mxv = v[i];
            // cout << mx << " " << mxv << endl;
        }
    }
 
    cout << mx << endl; mxv = mxv - mx+1;
    for (int i = 1; i <= n; i++){
        if (v[i] == mxv){
            cout << i << " "; mxv++;
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}