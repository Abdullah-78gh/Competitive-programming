#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 5;
 
int a[N], ans[N], xr[N];
struct qry{ int r, l, idx;};
 
void updateBIT(vector<int> &BITree, int n, int index, int val) {
    while (index <= n) {
        BITree[index] ^= val;
        index += index & (-index);
    }
}
 
int getSum(vector<int> &BITree, int index) {
    int sum = 0;
    while (index > 0) {
        sum ^= BITree[index];
        index -= index & (-index);
    }
    return sum;
}
 
void constructBITree(int n, vector < qry > &qr) {
    vector<int> BITree(n + 1, 0);
    unordered_map<int, int> last;
    int j = 0;
 
    for (int i = 1; i <= n; i++) {
        if (last[a[i]] != 0)updateBIT(BITree, n, last[a[i]], a[i]);
        updateBIT(BITree, n, i, a[i]);
        last[a[i]] = i;
 
        while (qr[j].r == i){
            int L = qr[j].r, R = qr[j].l - 1;
            ans[qr[j].idx] = (getSum(BITree, R) ^ getSum(BITree, L) ^ xr[R] ^ xr[L]);
            j++;
        }
    }
}
 
 
void solve() {
    int n; cin >> n;
    xr[0] = 0;
    for (int i = 0; i < n; i++){ cin >> a[i+1]; xr[i+1] = a[i+1] ^ xr[i];}
 
    int q; cin >> q;
    vector < qry > qr(q+1);qr[q].r = 1e7;
 
    for (int i = 0; i < q; i++){cin >> qr[i].l >> qr[i].r; qr[i].idx = i+1;}
    
    sort(qr.begin(), qr.end(), [](const qry &a, const qry &b) {return a.r < b.r;});
 
    constructBITree(n, qr);
    for (int i = 1; i <= q; i++){
        cout << ans[i] << endl;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}