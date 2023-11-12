#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<bool> visited(n, false);
    for(int &x : v) cin >> x;
    int cur_ind = n-1;
    int cur_k = 0;
    bool ans;
    while(true){
        // cout << cur_ind << " ";
        if(!visited[cur_ind]){
            if (v[cur_ind] > n) {
                ans = false;
                break;
            }
            cur_k++;
            if(cur_k == k) {
                ans = true;
                break;
            }
            visited[cur_ind] = true;
            cur_ind = (cur_ind - v[cur_ind] + n) % n;
        } else {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes\n";
    else cout << "No\n";

    // cout << "\n**********\n";

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