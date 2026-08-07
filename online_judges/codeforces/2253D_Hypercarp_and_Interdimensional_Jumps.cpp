#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll fun(ll sum, ll n){
    return (sum >= (n*(n+1))/2);
}
 
void solve() {
    ll n, m; cin >> n >> m;
 
    ll lo = 0, hi = 1e8, mid, ans = 0;
 
    while(lo <= hi){
        mid = (lo+hi)>>1;
 
        if (fun(n+m, mid)){ans = max(ans, mid); lo = mid+1;}
        else hi = mid-1;
    }
    // cout << ans << endl;
 
    ll mx = ans;
    ll bal = (n+m+1 - (mx*(mx+1))/2)/2;
 
    vector<char> a(mx+1, -1);
 
    ll set;
    if (n > m){
        ll use = n - bal;
        for (ll i = ans; i >= 1; i--){
            if (use - i >= 0){
                use -= i;
                // a[i] = 'Y';
                a[ans - i + 1] = 'X';
            }
            else a[ans - i + 1] = 'Y';
        }
    }
    else {
        ll use = m - bal;
        for (ll i = ans; i >= 1; i--){
            if (use - i >= 0){
                use -= i;
                a[ans - i + 1] = 'Y';
            }
            else a[ans - i + 1] = 'X';
        }
    }
 
 
    ll aa = 0, bb = 0;
    for (ll i = 1; i <= ans; i++){
        cout << a[i];
        // // if (n > m){
        //     if (a[i] == 0)cout << 'Y';
        //     else cout << 'X';
        // // }
        // // else {
        // //     if (a[i] == 0)cout << 'X';
        // //     else cout << 'Y';
        // // }
        if (a[i] == 'X')aa += i;
        else bb += i;
    }
    cout << endl;
    // cout << bb << " " << aa << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}