#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int a, b; cin >> a >> b;
 
    int y = a/2, x = (a+1)/2;
    if (b > y-1+x-1){cout << -1 << endl; return;}
    else {
        a -= 2;
        bool ok = 0;
        string s1 = "0", s2 = "1";
        while(a--){
            if (b){
                if (!ok)s1.push_back('0'); 
                else s2.push_back('1');b--;
            }
            else {
                if (!ok){
                    if (s1.back() == '1')s1.push_back('0'); 
                    else s2.push_back('0');
                }
                else {
                    if (s1.back() == '0')s1.push_back('1'); 
                    else s2.push_back('1');
                }
            }
            ok = !ok;
        }
        reverse(s1.begin(), s1.end());
        cout << s1 << s2 << endl;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}