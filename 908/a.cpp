#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << s[n-1] << el;
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