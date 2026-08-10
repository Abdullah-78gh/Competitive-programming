#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll N = 2e5+1, mod = 998244353;
ll f[N], invf[N];
 
 
ll power(long long n, long long k) {
    ll ans = 1 % mod; n %= mod; if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}
void com(){
    f[0] = 1;
    for (ll i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (ll i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}
 
ll nCr(ll n, ll r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
 
ll nPr(ll n, ll r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[n - r] % mod;
}
 
void solve() {
    string s; cin >> s;
    ll n = s.size();
 
    ll a = 0, aa = 1, c = 1;
    for (ll i = 1; i < n; i++){
        if (s[i] == s[i-1])c++;
        else {
            aa = 1ll * aa * c % mod;
            a += c-1;
            c = 1;
        }
    }
    aa *= c; aa %= mod;
    a += c-1;
    aa = 1ll * f[a] * aa; aa %= mod;
    cout << a << " " << aa << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    com();
    ll t; cin >> t; while(t--)
    solve();
}