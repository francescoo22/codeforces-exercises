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
    int a = -1, b = -1;
    for(int i=0; i<n; i++){
        char s;
        cin >> s;
        if(s == 'B') b = i;
        else if(a == -1) a = i;
    }

    if(a == -1 || b == -1 || b-a < 0) cout << "0\n";
    else cout << b - a << el;
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