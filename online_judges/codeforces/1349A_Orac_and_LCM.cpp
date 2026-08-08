#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200005;
bool prime[N];
 
void fun(){
    memset(prime, 1, sizeof(prime));
    for (ll i = 2; i < N; i++){
        if (prime[i])for (ll j = i*i; j < N; j += i)prime[j] = 0;
    }
}
 
void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (auto &x: v)cin >> x;
 
    ll ans = 1;
    for (ll i = 2; i < N; i++){
        vector<ll> add;
        ll zero = 0;
        if (prime[i] == 0)continue;
        
        for (ll j = 0; j < n; j++){
            ll cnt = 0;
            while (v[j] % i == 0)v[j] /= i, cnt++;
            if (!cnt)zero++;
            else add.push_back(cnt);
 
            sort(add.begin(), add.end());
            if (add.size() == 3)add.pop_back();
 
            if (zero == 2)break;
        }
 
        if (zero  == 2)continue;
        ll a = (zero == 0)?add[1]:add[0];
        
        while(a--)ans = 1ll * ans * i;
    }
 
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // ll t; cin >> t; while(t--)
    fun();
    solve();
}