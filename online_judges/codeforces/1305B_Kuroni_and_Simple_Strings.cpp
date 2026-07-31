#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    string s; cin >> s;
    int n = s.size();
 
    int i = 0, j = n-1;
    vector<int> a, b;
 
    int k = 0;
    for ( ; i < j; ){
        bool ok1 = 0, ok2 = 0;
        while(i < j && s[i] != '(')i++;
        while(i < j && s[j] != ')')j--;
 
        if (s[i] != '(' || s[j] != ')')break;
        a.push_back(i++);
        b.push_back(j--);
    }
 
    if (a.empty()){cout << 0 << endl; return;}
    reverse(b.begin(), b.end());
    cout << 1 << endl << a.size() + b.size() << endl;
    for (int i = 0; i < a.size(); i++)cout << a[i]+1 << " ";
    for (int i = 0; i < a.size(); i++)cout << b[i]+1 << " \n"[i+1 == (int)a.size()];
 
 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}