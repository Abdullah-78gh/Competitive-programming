#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
 
    vector< vector<int> > dp1(n, vector<int> (n, 1e9)),
                        dp2(n, vector<int> (n, 1e9)),
                       v(n, vector<int> (n));
 
    int zi = -1, zj = -1;
    dp1[0][0] = dp2[0][0] = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        
            if (!v[i][j]){zi = i, zj = j;continue;}
 
            if (i){
                dp1[i][j] = dp1[i-1][j];
                dp2[i][j] = dp2[i-1][j];
            }
            if (j){
                dp1[i][j] = min(dp1[i][j], dp1[i][j-1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][j-1]);
            }
            int tm = v[i][j];
            while (tm%2 == 0)tm /= 2, dp1[i][j]++;
            while (tm%5 == 0)tm /= 5, dp2[i][j]++;
        }
    }
    
    int mn = min(dp1[n-1][n-1] , dp2[n-1][n-1]);
    if (zi == -1 || mn <= 1){
        cout << mn << endl;
        bool ok = dp1[n-1][n-1] > dp2[n-1][n-1];
        
        string ans = "";
        int i = n-1, j = n-1;
 
        while(i>0 || j>0){
            if (i == 0){
                while(j--)ans.push_back('R');
            }
            else if (j == 0){
                while(i--)ans.push_back('D');
            }
            else if (ok){ // dp2 better
                if (dp2[i-1][j] <= dp2[i][j-1]){
                    i--;
                    ans.push_back('D');
                }
                else {
                    j--;
                    ans.push_back('R');
                }
            }
            else {
                if (dp1[i-1][j] <= dp1[i][j-1]){
                    i--;
                    ans.push_back('D');
                }
                else {
                    j--;
                    ans.push_back('R');
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;return;
    }
    cout << 1 << endl;
    string ans = "";
    int i = 0, j = 0;
    while(i != zi){
        ans.push_back('D'); i++;
    }
    while(j != n-1){
        ans.push_back('R'); j++;
    }
    while (i != n-1){
        ans.push_back('D'); i++;
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}