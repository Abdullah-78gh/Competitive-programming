#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {    
    int n;                          cin >> n;
    vector<int>v(n+1,0);
    for (int i = 1; i <= n; i++)    cin >> v[i];
    for (int i = 1; i <= n; i++){
        if (v[i] == i){}
        else {
            int x = i;
            while(x <= n){
                if (i == v[x])swap(v[i], v[x]);
                x *= 2;
            }
        }
    }
    if (is_sorted(v.begin(), v.end()))cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)
    solve();
}