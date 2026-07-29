#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10, mod = 998244353;
 
struct node {ll l, r, p, q;};
 
int power(long long n, long long k) {
    int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }return ans;
}
 
void solve() {
    int n, m; cin >> n >> m;
 
    vector<node> v(n);
    vector<int> dp(m+1, 0), sum(m+1); dp[0] = 1; sum[0] =  1;
 
    for (int i = 0; i < n; i++) cin >> v[i].l >> v[i].r >> v[i].p >> v[i].q;
 
    sort(v.begin(), v.end(), [](const node &a, const node&b){return a.r < b.r;});
 
    for (int i = 1, j = 0; i <= m; i++){
        sum[i] = sum[i-1];
        while(j < n && v[j].r == i){
            sum[i] = 1ll * sum[i] * (v[j].q - v[j].p) % mod;
            sum[i] = 1ll * sum[i] * power(v[j].q, mod-2) % mod; j++;
        }
    }
 
    for (int i = 1, j = 0; i <= m; i++){
        while (j < n && v[j].r == i){
            int pro = 1ll * v[j].p * power(v[j].q, mod-2) % mod;
            int npro = 1ll * sum[v[j].r] * power(sum[v[j].l - 1], mod-2) % mod;
            int tm = 1ll * (v[j].q - v[j].p) * power(v[j].q, mod-2) % mod;
            npro = 1ll * npro * power(tm, mod-2) % mod;
            pro  = 1ll * pro * npro % mod;
 
            int add = 1ll *  dp[v[j].l - 1] * pro % mod;
            dp[i] = (0ll + dp[i] + add) % mod; j++;
        }
    }
    cout << dp[m] << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}