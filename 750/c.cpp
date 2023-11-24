#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

string s;

bool is_pal(string s){
    for(int i=0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

int get_ans (const vector<int> &v, int size){
    int i=0, j=v.size() - 1;
    int ans = 0;
    for (int x:v) // cout << x << " ";
    // cout << el;
    while(i < j){
        // cout << i << " " << j << el;
        if(v[i] + v[j] == size) {
            i++;
            j--;
        } else {
            ans++;
            if (v[i] + v[j] < size) i++;
            else j--;
        }
    }
    if(i == j){
        if(size % 2 == 1 || v[i] != size / 2) ans++;
    }
    
    // cout << el;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cin >> s;
    if(is_pal(s)) {
        cout << "0\n";
        return;
    }
    set<char> letters;
    int ans = -1;
    for(char c : s) letters.insert(c);
    for(char c : letters){
        string without_c = "";
        for(auto c2 : s) {
            if(c2 != c) without_c += c2;
        }
        if(!is_pal(without_c)) continue;

        vector<int> pos;
        int j = 0;
        for(int i=0; i<n; i++){
            if(s[i] == c) pos.push_back(j);
            else j++;
        }

        // // cout << c << ": ";
        // for(int x : pos) // cout << x << " ";
        // // cout << without_c << el;

        // cout << without_c << el;
        int temp_ans = get_ans(pos, without_c.size());
        if(ans == -1) ans = temp_ans;
        else {
           ans = min(ans, temp_ans); 
        }
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