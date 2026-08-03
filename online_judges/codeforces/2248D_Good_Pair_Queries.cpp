#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, q; cin >> n >> q;
 
    string s1, s2; cin >> s1 >> s2;
    
    vector<int> v00(n, 0), v11(n, 0), v10(n, 0), v01(n, 0);
 
    for (int i = 0; i < n; i++){
        v00[i] = (s1[i] == '0' && s2[i] == '0');
        v11[i] = (s1[i] == '1' && s2[i] == '1');
        v10[i] = (s1[i] == '1' && s2[i] == '0');
        v01[i] = (s1[i] == '0' && s2[i] == '1');
 
        if (i)v00[i] += v00[i-1], v11[i] += v11[i-1], v10[i] += v10[i-1], v01[i] += v01[i-1];
    }
 
    while(q--){
        int l, r; cin >> l >> r; l-=2, r--;
        int len = r - l;
 
        int c00 = v00[r] - (l >= 0?v00[l]:0);
        int c11 = v11[r] - (l >= 0?v11[l]:0);
        int c01 = v01[r] - (l >= 0?v01[l]:0);
        int c10 = v10[r] - (l >= 0?v10[l]:0);
 
        if (abs(c10 - c01) <= (c11+c00))cout << "YES\n";
        else cout << "NO\n";
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}