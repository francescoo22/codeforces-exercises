#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n;
    cin >> n;
    vector<int> occ(n+1, 0);
    vector<bool> good_gcd(n+1, true);
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        occ[t]++;
        if(occ[t] == 1){
            for(int j=t; j<=n; j+=t){
                good_gcd[j] = false;
            }
        }
    }

    int ans = 0;
    vector<int> v_ans(n+1, 0);
    for(int i=n; i>0; i--){
        int tot = 0;
        for(int j=i; j<=n; j+=i){
            tot += occ[j];
        }
        int temp_ans = tot * (tot - 1) / 2;

        for(int j=i*2; j<=n; j+=i){
            temp_ans -= v_ans[j];
        }

        v_ans[i] = temp_ans;
        if(good_gcd[i]) ans += temp_ans;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}