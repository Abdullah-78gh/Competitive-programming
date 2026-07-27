#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n;
 
    string s[n];
    ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        ll c = count(s[i].begin(), s[i].end(), 'C');
        ans += c*(c-1)/2;
    }
    for (int i = 0; i < n; i++){
        int c = 0;
        for (int j = 0; j < n; j++)c += (s[j][i] == 'C');
        ans += (c*(c-1))/2;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin  t; while(t--)
    solve();
}