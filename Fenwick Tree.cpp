// Implementation of binary indexed tree
// Supports updates and range queries in O(log N) time
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+4;
typedef long long ll;
ll bit[MAXN];
void upd(int i, ll val) {
    for (; i<MAXN; i+=i&-i) bit[i]+=val;
}
ll qry(int i) {
    ll ans=0LL;
    for (; i; i-=i&-i) ans+=bit[i];
    return ans;
}
ll rng(int a, int b) {
    return qry(b)-qry(a-1);
}