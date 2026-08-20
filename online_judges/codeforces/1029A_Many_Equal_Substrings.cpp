#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a = 0;
    for (int i = 1; i < n; i++){
        bool ok = 1;
        for (int j = i; j < n; j++){
            if (s[j] != s[j - i])ok = 0;
        }
        if (ok){a = i;break;}
    }
    int j = a;
    if (!j){
        for (int i = 0; i < k; i++){
            for (int j = 0; j < n; j++)cout << s[j];
        }cout << endl;return;
    }
    for (int kk = 0; kk < k; kk++){
        for (int i = 0; i < j; i++)cout << s[i];
    }
    while(j < n)cout << s[j++];cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}