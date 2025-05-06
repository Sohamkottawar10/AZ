#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define mod 1000000000
#define pb push_back

const int mx = 1e5;

vector<int> is_prime(mx+1, 1);

void seive_prime(){
    for(int i=2;i<=mx;i++){
        if(is_prime[i]){
            // prime_nos.pb(i);
            for(int j=i*i;j<=mx;j+=i){
                is_prime[j] = 0;
            }
        }
    }
}

/* *********************************************************************************************************************************************************** */

int dp[100100][100];
int n,k;
int v[100100];

int rec(int lvl, int k){
    if(k == 0) return 0;
    if(lvl < 0) return 0;

    if(dp[lvl][k] != -1) return dp[lvl][k];

    int ans = dp[lvl-1][k];
    int sum=0;
    for(int i=1;i<=lvl;i++){
        sum += v[i];
        ans = max(ans, sum + rec(lvl-i, k));
    }

    dp[lvl][k] = ans;
}

void solve(){
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<rec(n-1, k)<<endl;
}

signed main() {  // Changed to normal int for clarity
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
