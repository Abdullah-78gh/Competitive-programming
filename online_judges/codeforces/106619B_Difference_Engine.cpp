#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
 
vector<ll> ans(N, 1);
 
void precom(){
    for (ll i = 2; i < N; i++){
        if (ans[i] != 1){continue;}
        ans[i] = 2;
        for (ll j = i+i; j < N; j += i){
            ll c = 0, tm = j;
            while(tm % i == 0){
                tm /= i; c++;
            }
            ans[j] *= (2*c+1);
        }
    }
    ans[1] = 0;
    for (int i = 2; i < N; i++){
        ans[i] = ans[i]/2 + ans[i-1];
    }
}
 
void solve() {
    int n; cin >> n;
    cout << ans[n] << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    precom();
    int t; cin >> t; while(t--)
    solve();
}