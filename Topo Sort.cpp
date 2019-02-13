// Topological sorting
#include <bits/stdc++.h>
using namespace std;
int N, M, c, out[10004];
vector<int> adj[10004];
queue<int> order;
int main() {
    scanf("%d%d", &N, &M);
    for (int m=0, a, b; m<M; m++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        out[b]++;
    }
    for (int n=1; n<=N; n++) {
        if (!out[n]) order.push(n);
    }
    while (!order.empty()) {
        int a=order.front();
        order.pop();
        c++;
        for (int i: adj[a]) {
            if (!--out[i]) order.push(i);
        }
    }
    if (c==N) printf("Y");
    else printf("N");
}
