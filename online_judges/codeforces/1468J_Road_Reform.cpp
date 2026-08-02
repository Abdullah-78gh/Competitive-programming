#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
 
struct node {int a, b, c; };
int parent[N];
 
int find(int v) {
    if (v == parent[v])return v;
    return parent[v] = find(parent[v]);
}
 
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)parent[b] = a;
}
 
void solve() {
    int n, m, k;
    ll ans = 0, cnt = 0;
    cin >> n >> m >> k;
    vector<node> v(m);
    for (int i = 0; i < m; i++) cin >> v[i].a >> v[i].b >> v[i].c;
 
    sort(v.begin(), v.end(), [](node x, node y){return x.c < y.c;});
    for (int i = 0; i <= n; i++)parent[i] = i;
 
    for (int i = 0; i < m; i++){
        int x = find(v[i].a), y = find(v[i].b);
        if (x != y){
            uni(v[i].a, v[i].b);
            ans += max(v[i].c - k, 0);
        }
    }
    if (ans == 0){
        ans = 2e9;
        for (int i = 0; i < m; i++){
            ans = min(ans, 0ll + abs(k - v[i].c));
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}