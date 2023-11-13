#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n;
    cin >> n;
    int m = 1;
    set<int>ms;
    ms.insert(1);
    while(2*m <= n) {
        m*=2;
        ms.insert(m);
    }

    // for(auto x : ms) cout <<x << " ";
    // cout << el;

    vector<int>v(n);
    for(int &x:v) cin >> x;

    bool ans = true;
    for(int i=1; i<n; i++){
        if(v[i] < v[i-1] && ms.find(i) == ms.end()) ans = false;
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";
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