#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, m; cin >> n >> m;
    if (n == m && n == 1)cout << 0 << endl;
    else if (n == 1 || m == 1)cout << 1 << endl;
    else cout << 2 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}