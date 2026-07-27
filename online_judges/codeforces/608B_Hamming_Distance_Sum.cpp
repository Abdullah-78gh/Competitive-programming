#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), nn = b.size(), ex = nn - n;
 
    ll ans = 0;
    vector<int> v(nn, 0); v[0] = b[0] == '1';
    for (int i = 1; i < nn; i++){
        v[i] += b[i] == '1';
        v[i] += v[i-1];
    }
 
    for (int i = 0; i < n; i++){
        ll one = v[i+ex] - ((i-1 < 0)?0:v[i-1]);
        if (a[i] == '0')ans += one;
        else ans += (ex+1 - one);
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}