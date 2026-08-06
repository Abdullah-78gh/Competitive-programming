#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    priority_queue<pair<int,int>> p;
    unordered_map<int,int> m;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        m[x]++;
    }
 
    for (auto &[x, y]: m){
        p.push({y, x});
    }
 
    int ans = 0;
    while(!p.empty()){
        if (p.size() == 1){
            auto pr = p.top();
            ans += min(pr.first, 2) * pr.second;
            break;
        }
        else {
            auto a = p.top();p.pop();
            auto b = p.top();p.pop();
 
            a.first--;
            b.first--;
 
            ans += (a.second + b.second);
 
            if (a.first)p.push(a);
            if (b.first)p.push(b);
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}