#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

int UB = 1e13;
vector<vector<int>> mem;
vector<ii> v;
int n;

int dp(int i, int b){
    if(mem[i][b] != -1) return mem[i][b];

    if(b == 0){
        mem[i][b] = 1 + min(dp(i + 1, 0), dp(i + 1, 1));
        return mem[i][b];
    } else {
        if (i == n-1 || v[i+1].first > v[i].second) {
            mem[i][b] = UB;
            return mem[i][b];
        } else {
            int j = i + 1;
            int min_end = v[j].second;

            while(j < n && v[j].first <= v[i].second) {
                min_end = min(min_end, v[j].second);
                j++;
            }

            while(j < n && max(min_end, v[i].second) >= v[j].first) j++;

            int discarded = j - i - 2;
            if(j == n){
                mem[i][b] = discarded;
                return mem[i][b];
            } else {
                mem[i][b] = discarded + min(dp(j, 0), dp(j, 1));
                return mem[i][b];
            }
        }
    }
}

void solve(){
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(all(v));

    mem = vector<vector<int>>(n, vector<int>(2, -1));
    mem[n-1][0] = 1;

    cout << min(dp(0, 0), dp(0, 1)) << el;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        v.clear();
        solve();
    }
    return 0;
}