// Finds first occurrence of substring in given string using hashing
// Linear run time
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+4, seed=131, mod=1e9+7;
string S, T;
ll pw[MAXN], hsh[2][MAXN];
int main() {
    cin>>S>>T;
    pw[0]=1;
    for (int i=0; i<S.length(); i++) {
        pw[i+1]=1LL*pw[i]*seed%mod;
        hsh[0][i+1]=(hsh[0][i]*seed%mod+S[i])%mod;
    }
    for (int i=0; i<T.length(); i++) hsh[1][i+1]=(hsh[1][i]*seed%mod+T[i])%mod;
    for (int i=T.length(); i<=S.length(); i++) {
        if(((hsh[0][i]-(hsh[0][i-T.length()]*pw[T.length()])%mod)%mod+mod)%mod==hsh[1][T.length()]) {
            printf("%d", i-T.length());
            return 0;
        }
    }
    printf("-1");
}
