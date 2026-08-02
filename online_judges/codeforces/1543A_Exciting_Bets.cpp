#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll a, b; cin >> a >> b;
    if (a > b)swap(a, b);
 
    ll gc = b - a;
    ll dis = (gc == 0 ? 0 : min(b % gc, gc - b % gc));
    cout << gc << " " << dis << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}