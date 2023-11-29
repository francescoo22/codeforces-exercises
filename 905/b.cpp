#include <bits/stdc++.h>
#define el "\n"
// #define int int64_t
#define all(x) (x).begin(), (x).end()
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n, t;
    cin >> n >> t;
    // adj[time][node] : list
    // vector<vector<vector<int>>> adj(t, vector<vector<int>>(n));
    vector<vector<ii>> adj(n); // node, time
    for(int i=0; i<t; i++){
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    int k;
    cin >> k;
    // vector<int> times(k);
    vector<set<int>> times(t);
    for(int i=0; i<k; i++){
        int time;
        cin >> time;
        time--;
        times[time].insert(i);
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<bool> visited(n, false);
    pq.push({0,0});
    while(!pq.empty() && pq.top().second != n-1){
        auto [time, node] = pq.top();
        // cout << time << " " <<node + 1 << endl;
        pq.pop();
        if(visited[node]) continue;

        visited[node] = true;
        for(auto[next, moment] : adj[node]){
            if(visited[next]) continue;
            auto lb = times[moment].lower_bound(time);
            if(lb != times[moment].end()){
                pq.push({*lb + 1, next});
            }
        }
    }

    if(pq.empty()) cout << "-1\n";
    else cout << max(pq.top().first, 1);
    // else cout << pq.top().first + 1;
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