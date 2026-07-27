#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 1001, mod = 1e9 + 7;
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
    vector<int > v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
 
    int nn = count(v.begin(), v.end(), v[n-k]);
    int r = k - (n -((lower_bound(v.begin(), v.end(), v[n-k]+1)) - v.begin()));
 
    cout << nCr(nn, r) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    com();
    int t; cin >> t; while(t--)
    solve();
}