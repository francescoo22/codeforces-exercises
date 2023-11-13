#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

int MOD = 1000000007, pow2[61];
ii gs[61];
vector<ii> _ranges;

int sum (int x, int y){
    x %= MOD;
    y %= MOD;
    return (x+y) % MOD;
}
 
int sub (int x, int y){
    x %= MOD;
    y %= MOD;
    return (x-y+MOD) % MOD;
}
 
int mul (int x, int y){
    x %= MOD;
    y %= MOD;
    return (x*y) % MOD;
}


int log_a_to_base_b(__int128_t a, __int128_t b)
{
    __int128_t ans = 0, cur = 1;
    while(cur*b <= a){
        ans++;
        cur*=b;
    }
    return ans;
}

int g(int x){
    int l2 = log_a_to_base_b(x, 2);
    return log_a_to_base_b(x, l2);
}

int find(int x, int from, int to){
    if(from == to) return to;
    int mid = (from + to) / 2;
    if(g(mid) >= x){
        return find(x, from, mid);
    } else {
        return find(x, mid + 1, to);
    }
}
    
void solve(){
    int64_t l, r;
    cin >> l >> r;
    int ans = 0;
    for(int i=0; i<_ranges.size() - 1; i++){
        auto[x, gx] = _ranges[i];
        auto[y, gy] = _ranges[i + 1];
        if(l >= x && l < y){
            int to = y-1 > r ? r : y-1;
            ans = sum(ans, mul(to-l+1, gx));
            l = to + 1;
        } else {
            continue;
        }
        if(l > r) break;
    }
    cout << int64_t(ans % MOD) << el;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pow2[0] = 1;
    for(int i=1; i<=60; i++) pow2[i] = 2 * pow2[i-1];
    for(int i=2; i<60; i++){
        gs[i].first = g(pow2[i]);
        gs[i].second = g(pow2[i+1] - 1);
        auto [fst, scd] = gs[i];
        _ranges.push_back({pow2[i], fst});
        if(fst != scd){
            int next_pos = find(scd, pow2[i], pow2[i+1] - 1);
            _ranges.push_back({next_pos, scd});
        }
    }
    _ranges.push_back({int(1e18) + 1, 10});

    int64_t t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}