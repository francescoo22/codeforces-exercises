#include <bits/stdc++.h>
#define el "\n"
#define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void print_path(const vector<int> &prev, int cur){
    if(cur == 1) cout << "1 ";
    else {
        print_path(prev, prev[cur]);
        cout << cur << " ";
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ii>>adj(n+1);

    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<int> prev(n+1, -1);
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    
    pq.push({0, 1, 1});
    while(!pq.empty() && get<1>(pq.top()) != n ){
        auto [w, node, prev_node] = pq.top();
        pq.pop();
        if(prev[node] == -1){
            prev[node] = prev_node;
            for(auto[next_node, next_weight] : adj[node]){
                if(prev[next_node == -1]){
                    pq.push({w + next_weight, next_node, node});
                }
            }
        }
    }
    
    if(!pq.empty()){
        auto [w, node, prev_node] = pq.top();
        prev[node] = prev_node;
        print_path(prev, n);
        cout << el;
    } else {
        cout << "-1\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}