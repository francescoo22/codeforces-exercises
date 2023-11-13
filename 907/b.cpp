#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n), queries;
    for(int &x:v) cin >> x;
    int cur_min = 31;
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        if (t < cur_min) queries.push_back(t);
        cur_min = min(t, cur_min);
    }

    vector<int> pow_two(31);
    pow_two[0] = 1;
    for (int i=1; i<31; i++){
        pow_two[i] = 2*pow_two[i-1];
    }

    for (int x:v){
        int max_div_ind = 0;
        while(max_div_ind < 30 && x % pow_two[max_div_ind + 1] == 0) max_div_ind++;
        int ans = x;
        for (int query : queries){
            if (query <= max_div_ind){
                ans += pow_two[query - 1];
            }
        }
        cout << ans << " ";
    }
    cout << el;
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