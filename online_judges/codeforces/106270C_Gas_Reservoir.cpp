#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool g[51][51][51] = {};
int cc[51][51][51] = {};
bool vis[51][51][51] = {};
 
int x, y, z; 
 
vector<int> sizeofcc;
int ccc = 1, sz = 0;
 
void dfs(int k,int i, int j){
    vis[k][i][j] = 1;
    cc[k][i][j] = ccc;
    sz++;
 
    if (k-1 >= 0 && !vis[k-1][i][j] && g[k-1][i][j]){
        dfs(k-1, i, j);
    }
    if (k+1 < z && !vis[k+1][i][j] && g[k+1][i][j]){
        dfs(k+1, i, j);
    }
    if (i-1 >= 0 && !vis[k][i-1][j] && g[k][i-1][j]){
        dfs(k, i-1, j);
    }
    if (i+1 < x && !vis[k][i+1][j] && g[k][i+1][j]){
        dfs(k, i+1, j);
    }
    if (j-1 >= 0 && !vis[k][i][j-1] && g[k][i][j-1]){
        dfs(k, i, j-1);
    }
    if (j+1 < y && !vis[k][i][j+1] && g[k][i][j+1]){
        dfs(k, i, j+1);
    }
}
 
void solve() {
    cin >> x >> y >> z;
 
    for (int k = 0; k < z; k++){
        for (int i = 0; i < x; i++){
            string s; cin >> s;
            for (int j = 0; j < y; j++){
                g[k][i][j] = ((s[j] == '.')?1:0);
                cc[k][i][j] = 0;
                vis[k][i][j] = 0;
            }
        }
    }
 
    sizeofcc.push_back(0);
    for (int k = 0; k < z; k++){
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                if (!vis[k][i][j] && g[k][i][j]){
                    sz = 0;
                    dfs(k, i, j);
                    sizeofcc.push_back(sz);
                    ccc++;
                }
            }
        }
    }
 
    int ans = 0;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            set<int> s;
            int cans = 0;
            for (int k = 0; k < z; k++){
                s.insert(cc[k][i][j]);
            }
            for (auto x: s){
                cans += sizeofcc[x];
            }
            ans = max(ans, cans);
        }
    }
 
    cout << ans << endl;
 
    ccc = 1;
    sizeofcc.clear();
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}