#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n, ones = 0, zeros = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(t == 0) zeros++;
        if(t == 1) ones++;
    }

    int ans = ones;
    for(int i=0; i<zeros; i++) ans *= 2;
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