#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
 
bool up(vector<int> &v){
    bool down = 0;
    for (int i = 1; i < v.size(); i++){
        if (v[i] < v[i-1])down = 1;
        else if (v[i] == v[i-1]){}
        else if (down)return 1;
    }return 0;
}
 
void solve() {
    int n; cin >> n;
    vector<int> v(n-1);
    for (int i = 0; i < n-1; i++) cin >> v[i];
 
    if (up(v)) {cout << 0 << endl; return;}
 
    for (int i = 0, j = n-2; i < j; ){
        if (v[i] == v[j] && v[i] != n-1){cout << 0 << endl; return;}
        if (v[i] < v[j]){
            int k = v[i];
            while(i < j && v[i] == k)i++;
        }
        else {
            int k = v[j];
            while (i < j && v[j] == k)j--;
        }
    }
 
    int l = 0, r = -1;
    for (int i = 0; i < n-1; i++)if (v[i] == n-1){l = i; break;}
    for (int i = n-2; i >= 0; i--)if (v[i] == n-1){r = i; break;}
    int nc = count(v.begin(), v.end(), n);
    int nc1 = count(v.begin(), v.end(), n-1);
 
    if (r - l + 1 <= 0 || nc > 0 || r - l + 1 != nc1){cout << 0 << endl; return;}
 
    ll ans = 2;
    
    for (int i = n - 2; i >= 1; i--){
        if (l-1 >= 0 && r+1 < n-1 && v[l-1] == v[r+1]){cout << 0 << endl; return;}
        if (l-1 >= 0 && v[l-1] == i){
            while (l - 1 >= 0 && v[l-1] == i)l--;
        }
        else if (r+1 < n-1 && v[r+1] == i){
            while(r + 1 < n-1 && v[r+1] == i)r++;
        }
        else {
            ans *= max(ll(r - l + 2 - (n - i)), 0ll);
            ans %= mod;
        }
        // cout << ans << " " << l << " " << r << endl;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}