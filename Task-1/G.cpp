#include <bits/stdc++.h>
using namespace std;

#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

int n, m;
vector<vi>adj;
vector<bool>visited;

void dfs(int node){
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]])
            dfs(adj[node][i]);
    }
}
void solve(){
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1, false);

    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ans;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << ans.size()-1 << endl;

    for(int i = 1; i < ans.size(); i++){
        cout << ans[i-1] << " " << ans[i] << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
}
