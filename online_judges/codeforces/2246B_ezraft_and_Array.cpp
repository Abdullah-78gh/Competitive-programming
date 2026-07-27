#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<ll> v(52); 
 
void solve() {
    ll n; cin >> n;
    if (n == 2)cout << -1 << endl;
    else for (int i = 0; i < n; i++)cout << v[i] << " \n"[i == n-1];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    v[0] = 1, v[1] = 2, v[2] = 3;
    for (int i = 3; i < 50; i++)v[i] = v[i-1] * 2;
    int t; cin >> t; while(t--)
    solve();
}