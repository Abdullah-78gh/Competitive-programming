#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// --- Modular arithmetic and combination template ---
const ll CN = 50+5, mod = 998244353;
// vll fact(CN);
ll mod_(ll x){x%=mod; x+=mod; return x%mod;}
ll mod_sum(ll x,ll y){x=mod_(x); y=mod_(y); return (x+y)%mod;}
ll mod_sub(ll x,ll y){x=mod_(x); y=mod_(y); return mod_(x-y);}
ll mod_mul(ll x,ll y){x=mod_(x); y=mod_(y); return (x*y)%mod;}
ll mod_pow(ll x,ll y){x=mod_(x); ll r=1; for(;y;y>>=1){if(y&1) r=mod_mul(r,x); x=mod_mul(x,x);} return r;}
ll mod_inv(ll x){return mod_pow(x,mod-2);}
ll mod_div(ll x,ll y){return mod_mul(x,mod_inv(y));}
// void f_fact(){fact[0]=1; for(ll i=1;i<CN;i++) fact[i]=i*fact[i-1]%mod;}
// ll nCr(ll n,ll r){if(r<0||r>n)return 0;return mod_mul(fact[n],mod_mul(mod_inv(fact[r]),mod_inv(fact[n-r])));}
// ll nPr(ll n,ll r){if(r<0||r>n)return 0;return mod_mul(fact[n],mod_inv(fact[n-r]));}
// --- End of modular template ---
 
void solve() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
 
    ll free = (x-1) * m + (y - 1) * n - (x-1)*(y-1);
    if (free == 0)cout << 1 << endl;
    else cout << mod_pow(2, free) << endl; 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}