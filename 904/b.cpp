#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    reverse(all(s));
    vector<int> zero_pos;
    for(int i=0; i<n; i++){
        if(s[i] == '0')zero_pos.push_back(i);
    }
    int cur_ans = 0;
    for(int i=0; i < zero_pos.size(); i++){
        cur_ans += zero_pos[i] - i;
        cout << cur_ans << " ";
    }

    for(int i=0; i< n-zero_pos.size(); i++){
        cout << "-1 ";
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