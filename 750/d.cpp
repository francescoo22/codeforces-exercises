#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

int sign (int x){
    return (x / abs(x));
}

void solve(){
    int n, s = 0, fst;
    cin >> n >> fst;
    vector<int> ans(n), v(n);
    v[0] = fst;
    for(int i=1; i<n; i++){
        int t;
        cin >> t;
        v[i] = t;
        if(s >= 0){
            ans[i] = -sign(t);
            s += t * ans[i];
        } else {
            ans[i] = sign(t);
            s += t * ans[i];
        }
    }

    if(s == 0) {
        ans[n-1] *= -1;
        s += v[n-1] * 2 * ans[n-1];
    }

    int mcd = gcd(abs(s), abs(fst));
    s /= mcd;
    fst /= mcd;

    ans[0] = -s;
    for(int i=1; i<n; i++){
        ans [i] *= fst;
    }

    // for(int x:v) cout << x << " ";
    // cout << el;
    // for(int x:ans) cout << x << " ";
    // cout << el;

    int tot_ans = 0, tot_abs = 0;
    for (int i = 0; i<n; i++) {
        int x = ans[i];
        tot_ans += x * v[i];
        tot_abs += abs(x);
    }

    if(tot_ans != 0) cout << "tot_ans " << tot_ans << " != 0" << el;
    if(tot_abs > 1e9) cout << "tot_abs > 1e9" << el;

    for(int x : ans) cout << x << " ";
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