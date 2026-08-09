#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
 
    sort(v.begin(), v.end());
    cout << min(v[2] - v[0], v[1]) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}