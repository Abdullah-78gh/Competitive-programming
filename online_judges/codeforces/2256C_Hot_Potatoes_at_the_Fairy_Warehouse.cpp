#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int a = 0, b = 0;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (count(s.begin(), s.end(), '1') == 2*n ){cout << n << " " << n << endl;return;}
    for (int i = 0; i < 2*n; i++){
        int nx = (i+1)%(2*n);
 
        if (i%2 == 0){
            if (s[i] == '1'){
                if (s[nx] == '1')b++;
                else a++;
            }
        }
        else {
            if (s[i] == '1'){
                if (s[nx] == '1')a++;
                else b++;
            }
        }
 
    }
 
    cout << a << " " << b << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}