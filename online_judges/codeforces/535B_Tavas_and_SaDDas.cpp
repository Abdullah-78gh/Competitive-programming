#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    string s; cin >> s;
    int n = s.size();
    ll ans = 0, num = 0;
    for (int i = n-1; i >= 0; i--){
        ans += (1ll<<(n - i - 1));
        if (s[i] == '7')num += (1ll<<(n - i - 1));
    }
    cout << ans+num << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}