#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
 
    int ao = 0, ae = 0, bo = 0, be = 0;
    for (int i = 0; i < n; i++){
        if (i&1){
            if (a[i] == '1')ao++;
            if (b[i] == '1')bo++;
        }
        else {
            if (a[i] == '1')ae++;
            if (b[i] == '1')be++;
        }
    }
 
    if (ao == bo && ae == be)cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}