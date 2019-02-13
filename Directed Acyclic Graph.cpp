// Checks if a given graph is a DAG
#include<bits/stdc++.h>
using namespace std;
int N, adj_mat[1004][1004], state[1004];
bool cycle;
void DFS(int cur) {
    state[cur]=1;
    for (int n=1; n<=N; n++) {
        if (adj_mat[cur][n]==1&&state[n]==0)
            DFS(n);
        else if (adj_mat[cur][n]==1&&state[n]==1)
            cycle=true;
    }
    state[cur]=2;
}
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        for (int m=1; m<=N; m++) {
            scanf("%d", &adj_mat[n][m]);
        }
    }
    for (int n=1; n<=N; n++) {
        DFS(n);
    }
    if (cycle==true)
        printf("%s", "NO");
    else
        printf("%s", "YES");
}
