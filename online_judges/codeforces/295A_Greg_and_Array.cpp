#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll N = 1e5+10;
ll a[N];
 
struct node {
    ll sum = 0;
};
 
node t[4*N];
ll lazy[4*N];
 
void push(ll node, ll begin, ll end) {
    if (lazy[node] == 0) return;
    t[node].sum = lazy[node] +  t[node].sum;
    if (begin != end) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}
 
node merge(node left, node right) {
    node ans;
    ans.sum = left.sum + right.sum;
    return ans;
}
 
void build(ll node, ll begin, ll end) {
    if (begin == end) {
        t[node].sum = a[begin];
        return;
    }
    ll mid = (begin + end) / 2;
    ll left = 2 * node;
    ll right = 2 * node + 1;
    build(left, begin, mid);
    build(right, mid + 1, end);
    t[node] = merge(t[left], t[right]);
}
 
void update(ll node, ll begin, ll end, ll leftRange, ll rightRange, ll val) {
    push(node, begin, end);
    if (end < leftRange || rightRange < begin) return;
    if (begin >= leftRange && end <= rightRange) {
        lazy[node] += val;
        push(node, begin, end);
        return;
    }
    ll mid = (begin + end) / 2;
    ll left = 2 * node;
    ll right = 2 * node + 1;
    update(left, begin, mid, leftRange, rightRange, val);
    update(right, mid + 1, end, leftRange, rightRange, val);
    t[node] = merge(t[left], t[right]);
}
 
node query(ll node, ll begin, ll end, ll leftRange, ll rightRange) {
    push(node, begin, end);
    if (end < leftRange || rightRange < begin) return {0};
    if (begin >= leftRange && end <= rightRange) {
        return t[node];
    }
    ll mid = (begin + end) / 2;
    ll left = 2 * node;
    ll right = 2 * node + 1;
    return merge(query(left, begin, mid, leftRange, rightRange), query(right, mid + 1, end, leftRange, rightRange));
}
 
struct vupd {ll l, r, d;};
 
void solve() {
    ll n, m, k; cin >> n >> m >> k;
 
    for (ll i = 1; i <= n; i++) cin >> a[i];
 
    build(1, 1, n);
 
    vector<vupd> v(m+1);
    vector<ll> sum(m+1, 0);
 
    for (ll i = 1; i <= m; i++)cin >> v[i].l >> v[i].r >> v[i].d;
 
    for (ll i = 1; i <= k; i++){
        ll l, r; cin >> l >> r;
        sum[l]++;
        if (r+1 <= m)sum[r+1] -= 1;
    }
 
    for (ll i = 2; i <= m; i++)sum[i] += sum[i-1];
    for (ll i = 1; i <= m; i++)v[i].d *= sum[i];
 
    for (ll i = 1; i <= m; i++){
        update(1, 1, n, v[i].l , v[i].r, v[i].d);
    }
    for (ll i = 1; i <= n; i++){
        cout << query(1, 1, n, i, i).sum << " \n"[i == n];
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // ll t; cin >> t; while(t--)
    solve();
}