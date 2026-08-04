#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
 
    int c = 1, ok = 0;
    for (int i = 1; i < n; i++){
        c += (s[i] != s[i-1]);
        if (i+1 < n){
            if (s[i] != s[i+1] && s[i] != s[i-1]){
                if (!ok)ok++;
                if (s[i-1] == s[i+1] && ok == 1)ok++;
            } 
        }
    }
    cout << c - ok << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}