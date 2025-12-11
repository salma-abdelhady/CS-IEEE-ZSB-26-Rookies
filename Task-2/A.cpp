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

const int N = 100000;
int n, m; vector<int> adj[N]; bool vis[N];
int parent[N];

int bfs(int start, int end){
    queue<pair<int,int>> q;

    q.push({start,0});
    parent[start] = -1;
    vis[start] = 1;

    while(!q.empty()){
        pair<int,int>p = q.front();
        q.pop();
        int node = p.first, cost = p.second;
        if(node == end) return 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                parent[it] = node;
                q.push({it,cost+1});
            }
        }
    }

    return 0;
}

void solve(){
    cin >> n >> m;

    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = bfs(1,n);

    if(ans == -1){
        cout << "IMPOSSIBLE";
        return;
    }

    vi path;
    int cur = n;
    while(cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(all(path));

    cout << path.size() << "\n";
    for(auto &it : path) cout << it << " ";
}
int32_t main(){
    FastIO();
    solve();
}
