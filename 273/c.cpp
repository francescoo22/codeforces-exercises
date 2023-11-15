#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    while((a + b + c) % 3 != 0){
        if(a > b && a > c){
            a--;
        } else if(b > c){
            b--;
        } else {
            c--;
        }
    }
    int ans = (a+b+c) / 3, mx = max(a, max(b,c));
    if(mx > ans*2) ans -= mx - ans * 2;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while(t--)
        solve();
    return 0;
}