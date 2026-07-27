#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<pair<int,int> > row(n), col(n);
    vector ans(n, vector<int>(n, 0));
    vector<bool> visC(n, 0);
    for (int i = 0; i < n; i++){
        cin >> row[i].first;
        row[i].second = i;
    }
    for (int i = 0; i < n; i++){
        cin >> col[i].first;
        col[i].second = i;
    }
 
    sort(row.begin(), row.end());
    sort(col.rbegin(), col.rend());
 
    for (int i = 0; i < n; i++){
        int r = row[i].second;
        int need = row[i].first;
 
        for (int j = 0; j <= i; j++){
            int jidx = col[j].second;
            int jv = col[j].first;
            
            int mn = min(need, jv);
            need -= mn;
            col[j].first -= mn;
            ans[r][jidx] += mn;
            if (need == 0)break;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << ans[i][j] << " \n"[j == n-1];
        }
    }
    for (int i = 0; i < n; i++){
        cout << row[i].second+1 << " \n"[i == n-1];
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}