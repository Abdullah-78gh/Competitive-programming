#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x <= n)v[x]++;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--){
        ans = max(ans, v[i]);
        for (int j = i+i; j <= n; j += i){
            v[j] += v[i];
            ans = max(ans, v[j]);
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}