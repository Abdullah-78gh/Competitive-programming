#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n; cin >> n;
    vector<ll> v(n), ans;
    for (auto &x: v) cin >> x;
 
    if (accumulate(v.begin(), v.end(), 0ll) <= 0){cout << -1 << endl;return;}
 
    multiset<ll> pos, neg;
    ll zero = 0;
    
    for (auto x: v){
        if (x == 0)zero++;
        else if (x < 0)neg.insert(x);
        else pos.insert(x);
    }
 
    ll cur = *pos.begin();
    ans.push_back(cur);
    pos.erase(pos.begin());
 
    while(!pos.empty() || !neg.empty() || zero > 0){
        auto next = neg.upper_bound(-cur);
 
        if (next != neg.end()){
            cur += *next;
            ans.push_back(cur);
            neg.erase(next);
        }
        else if (zero > 0){
            // cout << "testing  " << zero << endl;
            while(zero--)ans.push_back(cur);
            // cout << "testing  " << ans.size() << endl;
        }
        else if (!pos.empty()){
            auto it = pos.begin();
            cur += *it;
            ans.push_back(cur);
            pos.erase(it);
        }
        else break;
        // cout << "testing  " << ans.size() << " " << ans.back() << endl;
    }
    for (ll i = 0; i < n; i++)cout << ans[i] << " \n"[i == n-1];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}