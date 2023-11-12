#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(all(b));
    reverse(all(b));

    int i = 0, j = 0;
    while(i < n || j < m){
        if(j >= m || (a[i] > b[j] && i < n)) {
            cout << a[i] << " ";
            i++;
        } else {
            cout << b[j] << " ";
            j++;
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