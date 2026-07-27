#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string excel(int n){
    string s = "";
    while(n){ n--;
        s = char(n % 26 + 'A') + s;
        n /= 26;
    }return s;
}
 
int it(string s){
    int n = 0;
    for (auto c: s){
        n *= 26;
        n += c - 'A' + 1;
    }return n;
}
 
void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n >= 4 && s[0] == 'R' && s[1] <= '9' && (int)count(s.begin(), s.end(), 'C') > 0){
        int r = 0, c = 0, i = 0;
        while(++i){
            if (s[i] == 'C')break;
            else r = r*10 + s[i] - '0';
        }
        while (++i < n)c = c*10 + s[i] - '0';
        cout << excel(c) << r << endl;
    } else {
        while(--n)if (s[n] >= 'A')break;
        string tm(s.begin(), s.begin()+n+1);
        string tm2(s.begin()+n+1, s.end());
        cout << 'R' << tm2 << 'C' << it(tm) << endl;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    solve();
}