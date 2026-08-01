#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
 
struct node {
    int l = 0, r = 0, m = 0;
};
 
int a[N];
node t[4*N];
 
node merge(node left, node right) {
    node ans;
    int mn = min(left.l, right.r);
    ans.m = left.m + right.m + mn;
    ans.l = left.l + right.l - mn;
    ans.r = left.r + right.r - mn;
    return ans;
}
 
void build(int node, int begin, int end) {
    if (begin == end) {
        if (a[begin] == '(')t[node].l = 1;
        else t[node].r = 1;
        return;
    }
    int mid = (begin + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, begin, mid);
    build(right, mid + 1, end);
    t[node] = merge(t[left], t[right]);
}
 
node query(int node, int begin, int end, int leftRange, int rightRange) {
    if (end < leftRange || rightRange < begin) {
        return {0, 0, 0};
    }
    if (begin >= leftRange && end <= rightRange) {
        return t[node];
    }
    int mid = (begin + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    return merge(query(left, begin, mid, leftRange, rightRange), query(right, mid + 1, end, leftRange, rightRange));
}
 
void solve() {
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    for (int i = 0; i < n; i++)a[i+1] = s[i];
 
    build(1, 1, n);
    while(q--){
        int a, b; cin >> a >> b;
        cout << 2 * query(1, 1, n, a, b).m << endl;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}