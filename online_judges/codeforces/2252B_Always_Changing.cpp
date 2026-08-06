#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
 
    int z = count(s.begin(), s.end(), '0');
    int o = count(s.begin(), s.end(), '1');
 
    if (abs(z - o) > 2){cout << "-1" << endl; return;}
    int zero = 0, one = 0;
    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1] && s[i] == '1')one++;
        else if (s[i] == s[i-1] && s[i] == '0')zero++;
    }
 
    if (zero < one)swap(zero, one);
    cout << zero + max(zero - 1, one) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}