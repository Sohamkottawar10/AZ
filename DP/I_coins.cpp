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

int n;
double p[3010];
double dp[3010][3010];

double rec(int lvl, int num_hds){
    if(lvl == n){
        if(num_hds >= n/2+1) return 1;
        return 0;
    }

    if(dp[lvl][num_hds] != -1) return dp[lvl][num_hds];

    double ans = p[lvl]*rec(lvl+1, num_hds+1) + (1-p[lvl])*rec(lvl+1, num_hds);
    return dp[lvl][num_hds] = ans;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0)<<endl;
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
