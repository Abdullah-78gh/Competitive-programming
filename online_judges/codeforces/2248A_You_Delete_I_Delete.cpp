#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; 
    string s; cin >> s;
    n = s.size();
    
    int z = 0, o = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '0' && !z)z++;
        else if (s[i] == '1' && !o)o++;
        else cout << s[i];
    }cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}