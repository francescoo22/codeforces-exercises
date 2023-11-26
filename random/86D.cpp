#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n, q, maxn = 0;
    cin >> n >> q;
    vector<int> v(n);
    vector<iii> queries(q);
    for(int &x: v) {
        cin >> x;
        maxn = max(maxn, x);
    }
    for (int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        queries[i] = {a, b, i};
    }
    
    int k = sqrt(n) * 2;
    sort(all(queries), [k](iii q1, iii q2){
        auto [a1, b1, i1] = q1;
        auto [a2, b2, i2] = q2;
        if(a1 / k != a2 / k) return a1 / k < a2 / k;
        else return b1 < b2;
    });
    
    vector<int> occ(maxn + 1, 0);
    vector<int> ans(q);
    int pow = 0;
    auto [fa, fb, fi] = queries[0];
    for (int i=fa; i<=fb; i++) {
        int prev_occ = occ[v[i]]++;
        pow -= prev_occ * prev_occ * v[i];
        pow += (prev_occ + 1) * (prev_occ + 1) * v[i];
    }
    ans[fi] = pow;
    
    for(int i=1; i<q; i++){
        auto[na, nb, ni] = queries[i];
        for(int j=fa; j<na; j++){
            int prev_occ = occ[v[j]]--;
            pow += (-2 * prev_occ + 1) * v[j];
        }
    
        for(int j=nb+1; j<=fb; j++){
            int prev_occ = occ[v[j]]--;
            pow += (-2 * prev_occ + 1) * v[j];
        }
    
        for(int j=na; j<fa; j++){
            int prev_occ = occ[v[j]]++;
            pow += (2 * prev_occ + 1) * v[j];
        }
    
        for(int j=fb+1; j<=nb; j++){
            int prev_occ = occ[v[j]]++;
            pow += (2 * prev_occ + 1) * v[j];
        }
    
        ans[ni] = pow;
        fa = na;
        fb = nb;
    }
    
    for(int x:ans) cout << x << el;
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