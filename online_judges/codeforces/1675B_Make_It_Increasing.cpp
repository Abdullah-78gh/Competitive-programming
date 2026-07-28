#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
 
    int ans = 0;
    for (int i = n-2; i >= 0; i--) {
        if (v[i+1] == 0) {cout << -1 << endl; return;}
        while (v[i] >= v[i+1])v[i] /= 2,ans++;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}