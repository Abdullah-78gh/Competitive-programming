#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
 
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    for (int i = 0; i < m; i++){
        if (a[i] > b[i]){cout << "NO\n"; return;}
    }
    if (n < 2*m){cout << "NO\n"; return;}
    reverse(b.begin(), b.end());
    for (int i = 0; i < m; i++){
        if (a[n - i - 1] < b[i]){cout << "NO\n"; return;}
    }
    cout << "YES\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}