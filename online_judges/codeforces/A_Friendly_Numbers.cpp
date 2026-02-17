#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d(int n){
    int sum = 0;
    while(n)sum += n%10, n /= 10;
    return sum;
}

void solve() {
    int n;                          cin >> n;
    int ans = 0;
    for (int i = n - 72; i <= n + 72; i++)ans += (i - d(i) == n);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)
    solve();
}



