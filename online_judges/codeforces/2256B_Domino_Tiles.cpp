#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
 
    int a[4] = {1, 1, 1, 1};
    for (int i = 0; i < n; i++){
        if ((i/2) % 2 == 0){
            if (s[i] == '1')a[0] = 0;
            else if (s[i] == '0')a[1] = 0;
        }
        else if ((i/2) % 2 == 1){
            if (s[i] == '1')a[1] = 0;
            else if (s[i] == '0')a[0] = 0;
        }
 
        
        if (((i+1)/2) % 2 == 0){
            if (s[i] == '1')a[2] = 0;
            else if (s[i] == '0')a[3] = 0;
        }
        else if (((i+1)/2) % 2 == 1){
            if (s[i] == '1')a[3] = 0;
            else if (s[i] == '0')a[2] = 0;
        }
    }
    cout << a[0] + a[1] + a[2] + a[3] << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}