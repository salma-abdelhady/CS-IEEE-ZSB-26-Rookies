#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

int n, m;
vector<vi> adj;
vector<bool> visited;
int nodes = 0, edges = 0;

void dfs(int node){
    visited[node] = true;
    nodes ++;
    edges += adj[node].size();
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]])
            dfs(adj[node][i]);
    }
}
void solve(){
    cin >> n >> m;

    adj.resize(n + 1);

    int u, v;
    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.resize(n + 1, false);

    bool valid = true;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            nodes = 0, edges = 0;
            dfs(i);
            edges /= 2;
            if(edges != (nodes * (nodes-1)) / 2){
                valid = false;
            }
        }
    }

    if(valid) cout << "YES\n";
    else cout << "NO\n";
}
int32_t main(){
    FastIO();
    solve();
}
