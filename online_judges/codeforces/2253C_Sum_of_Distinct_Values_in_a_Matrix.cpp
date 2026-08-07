#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n, m, x, y; cin >> n >> m >> x >> y;
    ll c = 0;
    
    vector<ll> v(n+m+1, 0);
 
    for (ll i = 0; i < x; i++){
        ll it; cin >> it;
        v[it]++;
    }
    for (ll i = 0; i < y; i++){
        ll it; cin >> it;
        v[it] += 2;
    }
 
    ll ans = 0;
 
    ll com = 0, nn = 0, mm = 0;
    for (ll i = n+m; i >= 1; i--){
        if (v[i] == 3){
            com++;
            ans += i;
        }
        else if (v[i] == 1){
            if (nn < n){
                nn++;
                ans += i;
            }
        }
        else if (v[i] == 2){
            if (mm < m){
                mm++;
                ans += i;
            }
        }
        if (nn + mm + com == n+m-1)break;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}