#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll=long long;
const ll INF=1e18;
 
template<class K,class V=null_type,bool Multi=false>
class ordered_tree{
    using P=pair<K,ll>;
    using Key=conditional_t<Multi,P,K>;
    tree<Key,V,less<Key>,rb_tree_tag,tree_order_statistics_node_update> t;
    ll id=0;
 
public:
    void insert(K x){
        if constexpr(Multi) t.insert({x,id++});
        else t.insert(x);
    }
 
    void insert(K x,V v){
        if constexpr(Multi) t.insert({x,id++},v);
        else t.insert(x,v);
    }
 
    void erase(K x){
        if constexpr(Multi){
            auto it=t.lower_bound({x,-INF});
            if(it!=t.end()&&it->first==x) t.erase(it);
        }else{
            t.erase(x);
        }
    }
 
    ll size(){return t.size();}
    bool empty(){return t.empty();}
 
    ll order_of_key(K x){
        if constexpr(Multi) return t.order_of_key({x,-INF});
        else return t.order_of_key(x);
    }
 
    ll order_of_key(P p){
        if constexpr(Multi) return t.order_of_key(p);
        else return 0;
    }
 
    auto find_by_order(ll k){
        return t.find_by_order(k);
    }
 
    auto lower_bound(K x){
        if constexpr(Multi) return t.lower_bound({x,-INF});
        else return t.lower_bound(x);
    }
 
    auto end(){return t.end();}
 
    ll count(K x){
        if constexpr(Multi)
            return t.order_of_key({x,INF})-t.order_of_key({x,-INF});
        else
            return t.find(x)!=t.end();
    }
};
 
template<class T>
using ordered_set=ordered_tree<T>;
 
template<class T>
using ordered_multiset=ordered_tree<T,null_type,true>;
 
template<class K,class V>
using ordered_map=ordered_tree<K,V>;
 
template<class K,class V>
using ordered_multimap=ordered_tree<K,V,true>;
 
void solve() {
    ll n; cin >> n; 
 
    ordered_multiset<ll> s;
    vector<ll> cnt(n+1, 0);
    ll ans = 0;
 
    for (ll i = 0; i < n; i++){
        ll x; cin >> x;
        auto it = s.lower_bound(x);
 
        if (it == s.end()){
            s.insert(x);
            continue;
        }
        else {
            ll idx = s.order_of_key(*it);
            ans += i - idx;
            s.insert(x);
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while(t--)
    solve();
}