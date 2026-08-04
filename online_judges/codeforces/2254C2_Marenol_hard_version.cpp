#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll inv(string a, string b){
    ll ans = 0, n = a.size();
    ll j = 0;
    ll q0 = 0, q1 = 0;
    for (ll i = 0; i < n; i++){
        if (b[i] == '1'){
            if (q1 == 0){
                while(a[j] != '1')j++, q0++;
                q1 = 1;j++;
            }
            ans += q0;
            q1--;
        }
        else {
            if (q0 == 0){
                while(a[j] != '0')j++, q1++;
                q0 = 1;j++;
            }
            ans += q1;
            q0--;
        }
    }return ans;
}
 
void solve() {
    // string a, b; cin >> a >> b;
    // cout << inv(a, b) << endl;return;
    ll n; cin >> n;
    string a, b, a1 = "", a2 = "", b1 = "", b2 = "";
    cin >> a >> b;
 
    ll ao = 0, ae = 0, bo = 0, be = 0;
    for (ll i = 0; i < n; i++){
        if (i&1){
            a1 = a1 + a[i];
            b1 = b1 + b[i];            
            if (a[i] == '1')ao++;
            if (b[i] == '1')bo++;
        }
        else {
            a2 = a2 + a[i];
            b2 = b2 + b[i];
            if (a[i] == '1')ae++;
            if (b[i] == '1')be++;
        }
    }
    
    if (ao == bo && ae == be)cout << inv(a1, b1) + inv(a2, b2) << endl;
    else cout << -1 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}