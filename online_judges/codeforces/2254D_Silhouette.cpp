#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n;
    vector<ll> v(n), tm;
    for (auto &x: v) cin >> x;
    map<ll,ll> rep;
    
    tm = v;
    sort(tm.begin(), tm.end());
    tm.push_back(1e18);
 
    ll mx = 0;
    if (tm[0] > 0){cout << -1 << endl; return;}
    for (ll i = 0; i < n; ){
        ll j = i+1;
        while(tm[j] == tm[i])j++;
 
        if (j == n){
            rep[tm[i]] = mx+1;break;
        }
 
        ll cnt = j - i;
        ll sum = (tm[j] - tm[i]);
        if ((sum % cnt) != 0){cout << -1 << endl; return;}
        ll val = (tm[j] - tm[i]) / cnt;
 
        if (val <= mx){cout << -1 << endl; return;}
 
        mx = max(mx, val);
        rep[tm[i]] = val;
        i = j;
    }
 
    for (int i = 0; i < n; i++){
        cout << rep[v[i]] << " \n"[i == n-1];
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}