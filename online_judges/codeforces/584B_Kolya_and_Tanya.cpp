#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
 
// --- Modular arithmetic and combination template ---
ll mod_(ll x){x%=mod; x+=mod; return x%mod;}
ll mod_sum(ll x,ll y){x=mod_(x); y=mod_(y); return (x+y)%mod;}
ll mod_sub(ll x,ll y){x=mod_(x); y=mod_(y); return mod_(x-y);}
ll mod_mul(ll x,ll y){x=mod_(x); y=mod_(y); return (x*y)%mod;}
ll mod_pow(ll x,ll y){x=mod_(x); ll r=1; for(;y;y>>=1){if(y&1) r=mod_mul(r,x); x=mod_mul(x,x);} return r;}
ll mod_inv(ll x){return mod_pow(x,mod-2);}
ll mod_div(ll x,ll y){return mod_mul(x,mod_inv(y));}
// --- End of modular template ---
 
void solve() {
    ll n; cin >> n;
 
    ll a = 1, b = 1;
    for (int i = 1; i <= 3*n; i++){
        a = a*3%mod;
        if (i <= n)b = b*7%mod;
    }
    cout << mod_sub(a, b) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}