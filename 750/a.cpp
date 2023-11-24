    #include <bits/stdc++.h>
    #define el "\n"
    #define int int64_t
    #define all(x) (x).begin(), (x).end()
    using namespace std;
    using iii = tuple<int, int, int>;
    using ii = pair<int, int>;
     
    vector<int> v;
     
    int bf (int f = 0, int s = 0, int index = 0){
        if(index == v.size()) return abs(f - s);
     
        int x = v[index];
        return min(bf(f+x, s, index+1), bf(f, s+x, index+1));
     
    }
     
    void solve(){
        int a, b, c;
        v.clear();
        cin >> a >> b >> c;
        if(a > 2) a = (a % 2) + 2;
        if(b > 2) b = (b % 2) + 2;
        if(c > 2) c = (c % 2) + 2;
        
        for(int i = 0; i<a; i++) v.push_back(1);
        for(int i = 0; i<b; i++) v.push_back(2);
        for(int i = 0; i<c; i++) v.push_back(3);
     
        cout << bf() << el;
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