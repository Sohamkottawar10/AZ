#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
// #define int long long
#define pb push_back
#define endl '\n'

const int mod = 998244353;
int dp[100100][6];

int n;
string s = "0100";

int rec(int lvl, int idx){
    if(lvl >= n){
        if(idx >= 4) return 0;
        return 1;
    }
    if(idx >= 4) return 0;

    if(dp[lvl][idx] != -1) return dp[lvl][idx];

    int ans = 0;
    ans += rec(lvl+1, idx);
    ans += rec(lvl+1, idx+1);

    return dp[lvl][idx] = ans;
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