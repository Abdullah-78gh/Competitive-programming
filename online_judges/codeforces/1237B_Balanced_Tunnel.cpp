#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), vis(n+1, 0);
    for (auto &x: a)cin >> x;
    for (auto &x: b)cin >> x;
 
    int i = 0, j = 0, ans = 0;
    while(i < n && j < n){
        if (a[i] == b[j]){i++;j++;}
        else if (vis[a[i]])i++;
        else {
            vis[b[j]] = 1;
            j++;
            ans++;
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}