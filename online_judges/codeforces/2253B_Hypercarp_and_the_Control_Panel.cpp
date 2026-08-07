#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    int ans = 1, mx = 0;
 
    vector<int> v(n);
    for (auto &x: v) cin >> x;
    for (int i = 1; i < n; i++){
        if (v[i] != v[i-1])ans++;
 
        if (i+2 < n){
            if (v[i] == v[i-1] && v[i+1] == v[i+2] && v[i] != v[i+1])mx = 2;
        }
 
        if (v[i] == v[i-1]){
            if (i+2 < n){
                if (v[i] != v[i+1] && v[i+2] != v[i])mx = max(mx, 1);
            }
            else if (i+1 < n){
                if (v[i+1] != v[i])mx = max(mx, 1);
            }
            
            if (i-3 >= 0){
                if (v[i-1] != v[i-2] && v[i-1] != v[i-3])mx = max(mx, 1);
            }
            else if (i-2 >= 0){
                if (v[i-1] != v[i-2])mx = max(mx, 1);
            }
        }
    }
 
    cout << ans + mx << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}