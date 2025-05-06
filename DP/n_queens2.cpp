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

// no. of ways to place n queens in nxn grid filled with non-blocking obstacles.

vector<string> grid;
int n=8;

void solve(){
    grid.assign(n,"");
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }


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
