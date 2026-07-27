#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    vector<pair<int,int> > v(n), sum(5e6+10, {-1, -1});
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v[i] = {x, i+1}; 
    }
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int s = v[i].first + v[j].first;
 
            if (sum[s].first == -1)sum[s] = {v[i].second, v[j].second};
            else if (sum[s].first != v[i].second && sum[s].second != v[i].second && sum[s].first != v[j].second && sum[s].second != v[j].second){
                cout << "YES\n";
                cout << sum[s].first << " " << sum[s].second << " " << v[i].second << " " << v[j].second << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}