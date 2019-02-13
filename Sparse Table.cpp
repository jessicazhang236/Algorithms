// Range max query using a sparse table
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+4;
int RMQ[20][MAXN*3];
inline void build() {
    for (int i=1; i<=19; i++) {
        for (int j=0; j+(1<<i-1)<MAXN*3; j++)
            RMQ[i][j]=max(RMQ[i-1][j], RMQ[i-1][j+(1<<i-1)]);
    }
}
int query(int l, int r) {
    r--;
    int ans=-1;
    for(int i=19;i>=0;i--)
        if(l+(1<<i)-1<=r) {
            ans=max(ans,RMQ[i][l]);
            l+=1<<i;
        }
    return ans;
}
int N, Q;
int main() {
    scanf("%d", &N);
    for (int n=0; n<N; n++) scanf("%d", &RMQ[0][n]);
    build();
    scanf("%d", &Q);
    for (int q=0, l, r; q<Q; q++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
}
