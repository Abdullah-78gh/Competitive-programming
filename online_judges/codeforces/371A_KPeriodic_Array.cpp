#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, k; cin >> n >> k;
 
    vector<int> v(n);
    for (auto &x: v)cin >> x;
 
    int ans = 0;
    for (int i = 0; i < k; i++){
        map<int,int> m;
        int mx = 0;
        for (int j = i; j < n; j += k){
            m[v[j]]++;
            mx = max(mx, m[v[j]]);
        }
        ans += n/k - mx;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}