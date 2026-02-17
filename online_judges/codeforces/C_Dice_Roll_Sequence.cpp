#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;                          cin >> n;
    vector<int>v(n), a(n,0);
    for (auto &x:v)                 cin >> x;
    int c = 0, ans = 0;
    for (int i = 1; i < n; i++){
        if (v[i]+v[i-1] == 7 || v[i] == v[i-1]){
            if (!c)c = 2;
            else c++;
        }
        else ans += c/2,c = 0;
    }ans += c/2;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)
    solve();
}
