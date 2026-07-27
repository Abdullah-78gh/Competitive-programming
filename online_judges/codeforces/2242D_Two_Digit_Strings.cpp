#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string a, b;
 
int lcs(int n, int m) {
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
 
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (a[ind1 - 1] == b[ind2 - 1]) {
                cur[ind2] = 1 + prev[ind2 - 1];
            }
            else cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        swap(prev, cur);
    }
    return prev[m];
}
 
void solve() {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++){
        a[i] -= '0';
        if (i)a[i] += (a[i-1] - '0');
        a[i] %= 10; a[i] += '0';
    }
    for (int i = 0; i < m; i++){
        b[i] -= '0';
        if (i)b[i] += (b[i-1] - '0');
        b[i] %= 10; b[i] += '0';
    }
    if (a.back() != b.back())cout << -1 << endl;
    else cout << lcs(n, m) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t; while(t--)
    solve();
}