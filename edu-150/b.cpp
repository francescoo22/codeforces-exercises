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
    int prev = -1;
    int fst = -1;
    bool b = true;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(fst == -1) fst = t;
        if(t >= prev && b){
            cout << "1";
            prev = t;
        } else if (b && t <= fst){
            cout << "1";
            b = false;
            prev = t;
        } else if (!b && t>=prev && t<=fst) {
            cout << "1";
            prev = t;
        } else {
            cout << "0";
        }
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