#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string tm(s.begin(), s.begin()+1);
    for (int i = 1; i < n; i++){
        if (s[i] == s[0])break;
        if (s[i] <= s[i-1])tm.push_back(s[i]);
        else break;
    }
    string r = tm;
    reverse(r.begin(), r.end());
    cout << tm << r << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}