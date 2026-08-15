#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;
 
    int z = count(v.begin(), v.end(), 0);
    int o = count(v.begin(), v.end(), 1);
    int r = n - z - o;
 
    if (n-z >= n/2)cout << 0 << endl;
    else if (z == n)cout << 1 << endl;
    else if (r)cout << 1 << endl;
    else cout << 2 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}