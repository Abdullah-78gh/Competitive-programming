#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;
 
    if (n & 1){cout << "NO"<< endl;return;}
    int mn = 0, mx = 1e9;
    for (int i = 0; i < n; i += 2){
        // if (v[i] > v[i+1])swap(v[i], v[i+1]);
        mx = min(mx, v[i]);
        mn = max(mn, v[i+1]);
    }
    // sort(v.begin(), v.end());
    if (mn + 2 <= mx)cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}