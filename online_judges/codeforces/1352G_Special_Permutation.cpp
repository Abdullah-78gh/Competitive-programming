#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    if (n < 4)cout << -1 << endl;
    else if (n == 4)cout << "3 1 4 2\n";
    else {
        int str = (n&1)?1:2;
        vector<int>ans;
 
        while(str+4 != n){ans.push_back(str); str += 2;}str--;
 
        ans.push_back(n - 4);
        ans.push_back(n - 1);
        ans.push_back(n - 3);
        ans.push_back(n);
        ans.push_back(n - 2);
 
        while(str >= 1){ans.push_back(str); str -= 2;}
 
        for (int i = 0; i < n; i++)cout << ans[i] << " \n"[i == n-1];
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}