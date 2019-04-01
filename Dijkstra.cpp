#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+4;
typedef pair<int, int> pii;
int N, M, st, lst, dist[MAXN];
vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main() {
	scanf("%d%d", &N, &M);
	memset(dist, 0x3f, sizeof(dist));
	for (int i=1, u, v, w; i<=M; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	scanf("%d", &st);
	dist[st]=0;
	q.push({0, st});
	while (!q.empty()) {
		pii p=q.top();
		int v=p.second;
		q.pop();
		for (auto i: adj[v]) {
			int u=i.first;
			int d=i.second;
			if (dist[v]+d<dist[u]) {
				dist[u]=dist[v]+d;
				q.push({dist[u], u});
			}
		}
	}
	scanf("%d", &lst);
	if (dist[lst]==0x3f3f3f3f) printf("Disconnected");
	printf("%d", dist[lst]);
}
