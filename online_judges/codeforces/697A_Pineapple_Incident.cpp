#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int t, s, x; cin >> t >> s >> x;
 
    if (t == x)cout << "YES\n";
    else {
        x -= t;
        if (x >= s){
            if (x%s == 0 || x%s == 1)cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}