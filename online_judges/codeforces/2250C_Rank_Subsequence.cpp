#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct node {
    int a, b, c, d;
};
 
void solve() {
    int n; cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
 
    for (int len = n; len > 0; len--){
        int l = 1, r = len;
        for (int i = 0; i < n; i++){
            if ((l >= v[i].a && l <= v[i].b) || (r >= v[i].c && r <= v[i].d)){
                // cout << l << " " << r << endl;
            }
            else {l++;r--;}
            if (l == len+1)break;
        }
        if (l == len+1){cout << len << endl; return;}
    }cout << 0 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}