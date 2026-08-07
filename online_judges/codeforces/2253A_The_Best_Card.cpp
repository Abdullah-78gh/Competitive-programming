#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
 
vector<bool> prime(N, 1);
 
void fun(){
    for (int i = 2; i < N; i++){
        if (prime[i] == 0)continue;
        for (int j = i+i; j < N; j += i){
            prime[j] = 0;
        }
    }
    // for (int i = 2; i < 10; i++)cout << prime[i] << endl;
 
}
 
void solve() {
    int n; cin >> n;
    if (prime[n+1] == 1)cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    fun();
    int t; cin >> t; while(t--)
    solve();
}