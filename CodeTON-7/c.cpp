#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<ii> a(n), b(n);
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        b[i] = {t, i};
    }
    sort(all(a));
    sort(all(b));

    int beauty = 0;
    for(int i=0; i<n; i++){
        if(a[i].first > b[(i+x) % n].first) beauty++;
    }

    if(beauty == x) {
        cout << "YES\n";
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[a[i].second] = b[(i+x) % n].first;
        }
        for(int x:ans) cout << x << " ";
        cout << el;
    } else {
        cout << "NO\n";
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