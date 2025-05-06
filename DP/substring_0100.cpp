#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
// #define int long long
#define pb push_back
#define endl '\n'

const int mod = 998244353;
int dp[100100][8];  // 8 due to  3 bits.

int n;
string s = "0100";

int rec(int lvl, int lastthree){
    if(lvl == n) return 1;
    if(dp[lvl][lastthree] != -1) return dp[lvl][lastthree];

    int ans=0;
    if(lvl>=3 && lastthree == 2){       // 2 can appear in two ways: 10 and 010 and we have to eliminate 010 and not 100(for 10), therefore put lvl>=3 condition.
        ans += rec(lvl+1, ((lastthree<<1)|1)&7);
    }
    else{
        ans += rec(lvl+1, ((lastthree<<1)|0)&7);
        ans += rec(lvl+1, ((lastthree<<1)|1)&7);
    }

    return dp[lvl][lastthree] = ans;
}

void solve(){
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, 0)<<endl;;
}

int main() {  // Changed to normal int for clarity
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    // solve();
    return 0;
}