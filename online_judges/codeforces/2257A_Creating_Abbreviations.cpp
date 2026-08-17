#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, m; cin >> n >> m;
    map<char,int> mp;
 
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        
        mp[s[0]-32]++;
    }
 
    bool ok = 1;
    for (int i = 0; i < m; i++){
        string s; cin >> s;
        
        for (char x: s){
            if (mp.find(x) == mp.end())ok = 0;
        }
    }
 
    cout << (ok?"YES": "NO") << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}