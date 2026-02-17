#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 3e5+5;

struct nd{
    int l, r, p;
};

vector<nd> g;
vector<int> val;

int dfs(int n){
    if (n == 0) return 0;
    
    if (g[n].l == 0 && g[n].r == 0){
        val[n] = 1;
        return 1;
    }
    
    int lv = dfs(g[n].l);
    int rv = dfs(g[n].r);
    val[n] = lv + rv + 1;
    return val[n];
}

void adfs(int n, ll &ans){
    if (n == 0) return;

    if (g[n].l == 0 && g[n].r == 0){
        ans = (ans + 1) % mod;
        adfs(g[n].p, ans);
        return;
    }
    
    ans = (ans + val[g[n].l] * 2) % mod;
    ans = (ans + val[g[n].r] * 2) % mod;
    ans = (ans + 1) % mod;
    adfs(g[n].p, ans);
}

void solve() {
    int n; cin >> n;
    
    g.assign(n+5, {0, 0, 0});
    val.assign(n+5, 0);
    
    for (int i = 1; i <= n; i++){
        int ll, rr; cin >> ll >> rr;
        g[i].l = ll;
        g[i].r = rr;
        if (ll != 0) g[ll].p = i;
        if (rr != 0) g[rr].p = i;
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        ll ans = 0;
        adfs(i, ans);
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) solve();
}