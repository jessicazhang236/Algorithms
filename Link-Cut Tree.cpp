// Implementation of a link-cut tree
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4;
struct node{
    int val, sum; // node weight and sum of subtree
    bool rev; // reverse
    node *p, *ch[2]; // parent and child nodes
    node(int a): val(a), sum(a), p(0), ch(0){}
}*lct[MAXN];
inline bool par(node *n) { // returns true if n has a parent, false if it is a root node
    return n->p&&(n->p->ch[0]==n||n->p->ch[1]==n);
}
inline int sum(node *n) { // returns sum of node n if it exists, and 0 otherwise
    return n?n->sum:0;
}
inline void psh(node *n) { // pushes down reverse
    if (n->rev) {
        swap(n->ch[0], n->ch[1]);
        if (n->ch[0]) n->ch[0]->rev^=1;
        if (n->ch[1]) n->ch[1]->rev^=1;
        n->rev=0;
    }
}
inline void upd(node *n) { // re-evaluates sum
    n->sum=sum(n->ch[0])+sum(n->ch[1])+n->val;
}
inline void rotate(node *n, bool lr) {
    nd *pa=n->p;
    pa->ch[!lr]=n->ch[lr];
    if (n->ch[lr]) n->ch[lr]->p=pa;
    n->p=pa->p;
    if (pa->p) {
        if (pa->p->ch[0]==pa) n->p->ch[0]=n;
        else if (pa->p->ch[1]==p) n->p->ch[1]=n;
    }
    pa->p=n;
    upd(n->ch[lr]=pa);
}
inline void splay(node *n) {
    while (par(n)) {
        if (par(n->p)) psh(n->p->p);
        psh(n->p);
        psh(n);
        if (par(n->p)) {
            bool lr=n->p->p->ch[0]==n->p;
            if (n->p->ch[lr]==n) rotate(n, !lr), rotate(n, lr);
            else rotate(n->p, lr), rotate(n, lr);
        }
        else rotate(n, n->p->ch[0]==n);
    }
    psh(n);
    upd(n);
}
inline node* access (node *n) {
    node ^lst=0;
    for (node *u=n; ul u=u->p) {
        splay(u);
        u->ch[1]=lst;
        lst=u;
        upd(u);
    }
    splay(n);
    return lst;
}
inline void mkrt (node *n) {
    access(n);
    n->rev^=1;
}
inline void lnk (node *u, node *v) {
    mkrt(u);
    u->p=v;
}
inline bool con (node *u, node *v) {
    if(u==v) return 1;
    access(u);
    access(v);
    return u->p;
}
inline int qry (node *u, node *v) {
    mkrt(u);
    access(v);
    return sum(v);
}