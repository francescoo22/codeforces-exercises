#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

int val(char c){
    switch (c)
    {
        case 'A': return 1;
        case 'B': return 10;
        case 'C': return 100;
        case 'D': return 1000;
        default:  return 10000;
    }
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<char> max_dx(n);
    max_dx[n-1] = 'A' - 1;
    for(int i=n-2; i>=0; i--){
        max_dx[i] = max(s[i+1], max_dx[i+1]);
    }

    int initial_val = 0;
    for(int i=0; i<n; i++){
        if(s[i] >= max_dx[i]) initial_val += val(s[i]);
        else initial_val -= val(s[i]);
    }

    vector<vector<int>> pos_sx(n);
    vector<int> cur_pos_sx(5);

    for(int i=0; i<n; i++) {
        pos_sx[i] = cur_pos_sx;
        if(s[i] >= max_dx[i]) cur_pos_sx[s[i] - 'A']++;
    }

    vector<int> first_occ(5, -1);
    vector<bool> more_occ(5, false);
    vector<vector<int>> single_neg(n, vector<int>(5, 0));
    for(int i=n-1; i>=0; i--){
        int index = s[i] - 'A';
        if(first_occ[index] == -1) first_occ[index] = i;
        else more_occ[index] = true;

        if(s[i] < max_dx[i]){
            bool b = true;
            int blocker = - 1;
            for(int i = index + 1; i < 5; i++){
                if(more_occ[i]) b = false;
                if(first_occ[i] != -1 && blocker != -1) b = false;
                else if(first_occ[i] != -1 && blocker == -1) blocker = first_occ[i];
            }

            if(b){
                single_neg[blocker][index]++;
            }
        }
    }

    int ans = initial_val;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            if(s[i] == 'A' + j) continue;

            // I am changing s[i] with 'A' + j
            int temp_ans = initial_val;
            char new_char = 'A' + j;
            if(s[i] >= max_dx[i]) temp_ans -= val(s[i]);
            else temp_ans += val(s[i]);
            if(new_char >= max_dx[i]) temp_ans += val(new_char);
            else temp_ans -= val(new_char);

            for(int c = j - 1; c >= 0; c--){
                temp_ans -= 2 * val('A' + c) * pos_sx[i][c];
            }

            for(int c = j; c < 5; c++){
                temp_ans += 2 * val('A' + c) * single_neg[i][c];
            }

            ans = max(ans, temp_ans);

        }
    }
    cout << ans  << el;
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