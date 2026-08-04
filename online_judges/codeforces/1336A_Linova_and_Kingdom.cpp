#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
 
vector<ll> g[N], vis(N, 0), child(N);
 
ll dfs(ll node){
    vis[node] = 1;
    ll cld = 0;
    for (auto x: g[node]){
        if (!vis[x]){
            cld += dfs(x);
        }
    }
    return child[node] = cld + 1;
}
 
void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> dis(n, 0), ans;
    bool vis[n] = {};
 
    for (ll i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    ll tm = dfs(0);
 
    queue<ll> q;
    q.push(0);
    vis[0] = 1;
    ans.push_back(0);
 
    while(!q.empty()){
        ll node = q.front();q.pop();
        for (auto x: g[node]){
            if (!vis[x]){
                vis[x] = 1;
                q.push(x);
                dis[x] = dis[node] + 1;
                ans.push_back(dis[x] - child[x] + 1);
            }
        }
    }
 
    ans[0] = (1-n);
    // for (auto x: ans)cout << x << " ";cout << endl;
 
    sort(ans.rbegin(), ans.rend());
    ll sum = 0;
    for (ll i = 0; i < k; i++)sum += ans[i];
    
    cout << sum << endl;
 
    for (ll i = 0; i < n; i++)g[i].clear(), vis[i] = 0;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // ll t; cin >> t; while(t--)
    solve();
}