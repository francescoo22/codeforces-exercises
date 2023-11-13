#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(), v.end());
    int i = 0, j = n-1, ans = 0, cc = 0;

    if(n == 1){
        ans = v[0] == 1 ? 1 : (v[0] + 1) / 2 + 1;
    }

    while(i<j){
        if (cc + v[i] < v[j]){
            cc += v[i];
            ans += v[i];
            i++;
            if(i == j) ans += (v[j] - cc + 1) / 2 + 1;
        } else {
            v[i] -= (v[j] - cc);
            ans += (v[j] - cc) + 1;
            j--;
            cc = 0;
            if(v[i] == 0) i++;
            if(i == j && v[i] != 1) ans += (v[j] - cc + 1) / 2 + 1;
            if(i == j && v[i] == 1) ans++;
        }
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