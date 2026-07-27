#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e5 + 10;
const int mod = 998244353;
 
int cntp[N] = {}, cntm[N] = {};
int f[N], invf[N];
 
int power(long long n, long long k) {
    int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}
 
void com(){
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}
 
int nCr(int n, int r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
 
void solve() {
    int n, k; cin >> n >> k;
 
    map<int,int> mp;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        mp[v[i].first] = 0;
        mp[v[i].second] = 0;
    } 
    int c = 0;
    for (auto &[x, y]: mp)mp[x] = c++;
    memset(cntp, 0, sizeof(cntp));
    memset(cntm, 0, sizeof(cntm));
 
    for (auto [x, y]: v){
        int X = mp[x], Y = mp[y];
        cntp[X]++; cntm[Y]++;
    }
 
    ll ans = 0;
    int cur = 0, nw = 0;
 
    for (int i = 0; i <= c; i++){
        nw = cntp[i];
        for (int j = 1; j <= min(nw, k); j++){
            ans += 1ll * nCr(cur, k - j) * nCr(nw, j) % mod;
            ans %= mod;
        }
        cur += nw; cur -= cntm[i];
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    com();
    // int t; cin >> t; while(t--)
    solve();
}