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
    vector<int> in1, in2, fi1, fi2;
    for(int i=0; i< n; i++){
        int l, r;
        cin >> l >> r;
        if(l != 1){
            in1.push_back(l);
            fi1.push_back(r);
        }
        if(r != m){
            in2.push_back(l);
            fi2.push_back(r);
        }
    }
    sort(all(in1));
    sort(all(in2));
    sort(all(fi1));
    sort(all(fi2));
    int ans = 0, cur = 0, i = 0, j = 0;
    while(i < in1.size()){
        if(in1[i] <= fi1[j]){
            cur++;
            i++;
        } else {
            cur--;
            j++;
        }
        ans = max(ans, cur);
    }
    i = 0;
    j = 0;
    cur = 0;

    while(i < in2.size()){
        if(in2[i] <= fi2[j]){
            cur++;
            i++;
        } else {
            cur--;
            j++;
        }
        ans = max(ans, cur);
    }

    cout << ans << el;
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