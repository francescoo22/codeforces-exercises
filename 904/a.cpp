#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

int dig_sum(int x){
    if(x < 10) return x;
    else return x%10 + dig_sum(x/10);
}

void solve(){
    int x, k;
    cin >> x >> k;
    while(dig_sum(x) % k != 0)x++;
    cout << x << el;
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