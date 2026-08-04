#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int ans = 0;
    while(1){
        sort(v.begin(), v.end());
        if (v[0] == v[1] || v[1] == v[2]){
            cout << ans << endl; return;
        }ans++;
        v[0]++;v[2]--;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}