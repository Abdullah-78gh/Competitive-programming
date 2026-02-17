#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;                          cin >> n;
    vector<int>v(n);
    for (auto &x:v)                 cin >> x;
    int ans = find(v.begin(), v.end(), 67) != v.end();
    cout << ((ans == 1)?"YES":"NO") << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)
    solve();
}