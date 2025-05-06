#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
#define endl '\n'

const int mod = 998244353;

int n;
int arr[200020];
int dp[200020][4];

int rec(int level, int st){
    if(level >= n && st==3) return 1;
    else if(level >= n && st != 3) return 0;

    if(dp[level][st] != -1) return dp[level][st];
    
    int ans = rec(level+1, st); // dont take
    if(st==0 && arr[level]==1) ans = (ans + rec(level+1, st+1)%mod)%mod;
    else if(st==1 && arr[level]==2) ans = (ans+rec(level+1, 2)%mod)%mod;
    else if(st==2 && arr[level]==2) ans = (ans+rec(level+1, 2)%mod)%mod;
    else if(st==2 && arr[level]==3) ans = (ans + rec(level+1, 3)%mod)%mod;

    return dp[level][st] = ans;
}

void solve(){
    cin>>n;
    for(int i=0;i<=n;i++) for(int j=0;j<4;j++) dp[i][j] = -1;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<rec(0,0)<<endl;
}

signed main() {  // Changed to normal int for clarity
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    // int t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}