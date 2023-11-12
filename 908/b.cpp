#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
    
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> occ;
    for(int &x: v){
        cin >> x;
        occ[x]++;
    }
    int gt2 = 0;
    int fst = -1, scd = -1;
    bool b1 = false, b2  = false;
    for (auto[key, val] : occ){
        if (val >= 2) {
            gt2++;
            scd = fst;
            fst = key;
        }
    }
    if (gt2 < 2){
        cout << "-1";
    } else{
        for (int x : v){
            if(x == fst && !b1){
                cout << "1 ";
                b1 = true;
            } else if (x == scd && !b2) {
                cout << "2 ";
                b2 = true;
            } 
            else {
                cout << "3 ";
            }
        }
    }
    cout << "\n";
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