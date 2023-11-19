#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int m;
    cin >> m;
    vector<int> n(m), l(m), r(m), sizes(m, 0);
    vector<vector<int>> a(m), c(m);
    int n_tot = 0, l_tot = 0, r_tot = 0;
    for(int i=0; i<m; i++){
        cin >> n[i] >> l[i] >> r[i];
        n_tot += n[i];
        l_tot += l[i];
        r_tot += r[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        for(int &x : a[i]) cin >> x;
        for(int &x : c[i]) {
            cin >> x;
            sizes[i] += x;
        }
    }

    if (n_tot < r_tot - l_tot + 1) {
        cout << "0\n";
    } else {
        int sz = r_tot - l_tot + 1;
        vector<int> rem(sz, r_tot), obb(sz, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n[i]; j++){
                int aa = a[i][j], cc = c[i][j];
                if(aa >= l_tot && aa <= r_tot){
                    obb[aa - l_tot] += max(int(0), cc + l[i] - sizes[i]);
                    int max_to_take = max(sizes[i] - cc, l[i]); 
                    rem[aa - l_tot] -= max(int(0), r[i] - max_to_take);
                }
            }
        }
        int ans = LONG_LONG_MAX;
        for (int i = l_tot; i <= r_tot; i++){
            int temp_ans = obb[i - l_tot];
            temp_ans += max(int(0), i - rem[i - l_tot]);
            ans = min(ans, temp_ans);
        }

        cout << ans << el;
    }
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