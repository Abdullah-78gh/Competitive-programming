#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T>
using ordered_multiset =
    tree<pair<int,int>, null_type, less<pair<int,int>>,
         rb_tree_tag, tree_order_statistics_node_update>;
 
void solve() {
    int n; cin >> n; 
 
    ordered_multiset<int> s;
    vector<int> cnt(n+1, 0);
    ll ans = 0;
 
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = s.lower_bound({x, -1});
 
        if (it == s.end()){
            s.insert({x, ++cnt[x]});
            continue;
        }
        else {
            int idx = s.order_of_key(*it);
            ans += i - idx;
            s.insert({x, ++cnt[x]});
        }
 
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}