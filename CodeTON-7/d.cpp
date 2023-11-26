#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;


void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    set<int> ones;
    int tot = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        tot += v[i];
        if (v[i] == 1) ones.insert(i);
    }

    for(int i=0; i<q; i++){
        int op;
        cin >> op;
        if(op == 1){
            int s;
            cin >> s;
            if(s > tot) {
                cout << "NO\n";
                continue;
            }

            if(s % 2 == 0 && ones.size() % 2 == 0){
                cout << "YES\n";
                continue;
            }

            if(s % 2 == 0 && ones.size() % 2 == 1){
                int first_one = *ones.begin();
                int last_one = *ones.rbegin();
                int l1 = 2 * first_one;
                int r1 = tot - l1 - 1;
                int l2 = 2 * (n - last_one - 1);
                int r2 = tot - l2 - 1;
                if(s > max({l1, l2, r1, r2})) cout << "NO\n";
                else cout << "YES\n";
                continue;
            }

            if(ones.size() == 0) {
                cout << "NO\n";
                continue;
            }
            if(ones.size() == 1) {
                cout << "YES\n";
                continue;
            }
            if(ones.size() % 2 == 1){
                cout << "YES\n";
            } else {
                int first_one = *ones.begin();
                int last_one = *ones.rbegin();
                int l1 = 2 * first_one + 1;
                int l2 = 2 * (n - last_one - 1) + 1;
                int mid = tot - l1 - l2;
                if(s > max(l1, l2) + mid + 1) cout << "NO\n";
                else cout << "YES\n";
            }

        } else {
            int ind, val;
            cin >> ind >> val;
            ind--;
            if(v[ind] != val){
                if(val == 1) {
                    ones.insert(ind);
                    tot--;
                }
                else {
                    ones.erase(ind);
                    tot++;
                }
            }
            v[ind] = val;
        }
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