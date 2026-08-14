#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, m; cin >> n >> m;
 
    int v[n][m], sum[n][m] = {};
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
 
    vector<pair<int,int> >a, b;
 
    for (int i = 0; i < m; i++)a.push_back({0, i});
    for (int i = 1; i < n; i++)a.push_back({i, 0});
    for (int i = 0; i < n; i++)b.push_back({i, 0});
    for (int i = 1; i < m; i++)b.push_back({n-1, i});
 
    for (auto [x, y]: a){
        int s = 0;
        int i = x, j = y;
        while(i < n && j < m){
            s += v[i][j];
            i++;j++;
        }
        i = x, j = y;
        while(i < n && j < m){
            sum[i][j] = s;
            i++;j++;
        }
    }
    for (auto [x, y]: b){
        int s = 0;
        int i = x, j = y;
        while(i >= 0 && j < m){
            s += v[i][j];
            i--;j++;
        }
        i = x, j = y;
        while(i >= 0 && j < m){
            sum[i][j] += s;
            i--;j++;
        }
    }
 
    int ans = 0;
    pair<int,int> x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans = max(ans, sum[i][j] - v[i][j]);
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}