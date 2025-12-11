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

const int N = 100000+5;
int n, m; vector<int> adj[N]; vi inDeg(N);

vi topologicalSort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }

    vi order;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        order.push_back(parent);
        for(int child: adj[parent]){
            if(--inDeg[child] == 0){
                q.push(child);
            }
        }
    }

    return order;
}

void solve(){
    cin >> n >> m;

    while(m--){
        int a, b; cin >> a >> b;
        inDeg[b]++;
        adj[a].push_back(b);
    }
    vi ans = topologicalSort();

    if(ans.size() != n){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}
int32_t main(){
    FastIO();
    solve();
}
