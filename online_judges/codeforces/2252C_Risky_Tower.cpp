#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool fun(vector< vector<ll> > t, ll sz, vector<ll> v, ll n, ll m){
 
    vector<ll> lim;
    for (ll i = n-1; i >= 0; i--){    
        lim.insert(lim.end(), t[i].begin(), t[i].end());
        sort(lim.rbegin(), lim.rend());
        while(lim.size() > sz)lim.pop_back();
 
        ll sum = accumulate(lim.begin(), lim.end(), 0ll);
 
        ll mn = *min_element(v.begin(), v.end());
 
        if (sum >= mn)return 1;
        
        v.pop_back();
    }return 0;
}
 
void solve() {
    ll n, m; cin >> n >> m;
 
    vector<ll> v(n);
    for (auto &x: v) cin >> x;
 
    vector< vector<ll> > t(n, vector<ll> (m));
 
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++)cin >> t[i][j];
    }
 
    ll lo = 1, hi = m-1, mid, ans = m;
 
    while(lo <= hi){
        mid = (lo+hi)/2;
 
        if (fun(t, mid, v, n, m)){hi = mid-1; ans = min(ans, mid);}
        else lo = mid+1;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}