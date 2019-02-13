// Implementation of segment tree that supports queries of minimum, gcd, and occurrences
#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r, minimum, gcd, occurrences;
};
int N, Q, elements[100004];
node segtree[300004];
int gcd(int a, int b) {
    if (a==0)
        return b;
    return gcd(b%a, a);
}
void push_up (int i) {
    segtree[i].minimum=min(segtree[i*2].minimum, segtree[i*2+1].minimum);
    segtree[i].gcd=gcd(segtree[i*2].gcd, segtree[i*2+1].gcd);
    segtree[i].occurrences=0;
    if (segtree[i].gcd==segtree[i*2].gcd)
        segtree[i].occurrences+=segtree[i*2].occurrences;
    if (segtree[i].gcd==segtree[i*2+1].gcd)
        segtree[i].occurrences+=segtree[i*2+1].occurrences;
}
void build (int i, int l, int r) {
    segtree[i].l=l;
    segtree[i].r=r;
    if (l==r) {
        segtree[i].minimum=elements[r];
        segtree[i].gcd=elements[r];
        segtree[i].occurrences=1;
        return;
    }
    int m=(l+r)/2;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    push_up(i);
}
void update (int cur, int src, int val) {
    int l=segtree[cur].l;
    int r=segtree[cur].r;
    if (l==r) {
        segtree[cur].minimum=val;
        segtree[cur].gcd=val;
        segtree[cur].occurrences=1;
        return;
    }
    int m=(l+r)/2;
    if (src<=m) {
        update(cur*2, src, val);
    }
    else {
        update(cur*2+1, src, val);
    }
    push_up(cur);
}
int Min(int i, int L, int R) {
    int l=segtree[i].l;
    int r=segtree[i].r;
    int m=(l+r)/2;
    if (L==l&&R==r)
        return segtree[i].minimum;
    else if (R<=m)
        return Min(i*2, L, R);
    else if (L>m)
        return Min(i*2+1, L, R);
    return min(Min(i*2, L, m), Min(i*2+1, m+1, R));
}
int GCD (int i, int L, int R) {
    int l=segtree[i].l;
    int r=segtree[i].r;
    int m=(l+r)/2;
    if (L==l&&R==r)
        return segtree[i].gcd;
    else if (R<=m)
        return GCD(i*2, L, R);
    else if (L>m)
        return GCD(i*2+1, L, R);
    return gcd(GCD(i*2, L, m), GCD(i*2+1, m+1, R));
}
int Count(int i, int L, int R, int val) {
    int l=segtree[i].l;
    int r=segtree[i].r;
    int m=(l+r)/2;
    if (L==l&&R==r) {
        if (segtree[i].gcd==val)
            return segtree[i].occurrences;
        else
            return 0;
    }
    else if (R<=m)
        return Count(i*2, L, R, val);
    else if (L>m)
        return Count(i*2+1, L, R, val);
    return Count(i*2, L, m, val)+Count(i*2+1, m+1, R, val);
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int n=1; n<=N; n++)
        scanf("%d", &elements[n]);
    build (1, 1, N);
    for (int q=0, l, r; q<Q; q++) {
        char command;
        scanf(" %c%d%d", &command, &l, &r);
        if (command=='C') {
            update(1, l, r);
        }
        else if (command=='M') {
            printf("%d\n", Min(1, l, r));
        }
        else if (command=='G') {
            printf("%d\n", GCD(1, l, r));
        }
        else {
            printf("%d\n", Count(1, l, r, GCD(1, l, r)));
        }
    }
}
