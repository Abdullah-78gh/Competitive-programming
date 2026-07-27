#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<string> a = {"3","4","5","6","7","8","9","10","J","Q","K","A"};
 
void solve() {
    vector<int>ok(12, 0);
    for (int i = 0; i < 17; i++) {
        string s; cin >> s;
        for (int j = 0; j < 12; j++)if (s == a[j])ok[j] = 1;
    }
 
    int cur = 0, ans = 0;
    for (int i = 0; i < 12; i++) {
        if (ok[i]) cur++;
        else cur = 0;
        ans = max(ans, cur);
    }
    cout << (ans >= 5 ? ans : 0) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}