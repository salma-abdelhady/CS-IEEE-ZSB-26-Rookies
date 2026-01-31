#include <bits/stdc++.h>

using namespace std;

#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
#define dpp(arr,val) memset(arr,val,sizeof(arr))
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
void UseFile(){freopen("divsnums.in", "r", stdin);}
const int MOD = 1000000007;
const int sz = 2e5+10;
const double PI = 3.14159265358979323846;

struct edge {
	int from, to, w;

	edge(int from, int to, int w): from(from), to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<edge>> adjlist(n);
    vi dist(n, 1e18);

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adjlist[a].push_back(edge(a, b, c));
    }
    
    int src = 0;
    dist[src] = 0;

    priority_queue<edge> q;
    q.push(edge(-1,src,0));

    while(!q.empty()){
        edge e = q.top();
        q.pop();

        if(e.w > dist[e.to]) continue;

        for(int i = 0; i < adjlist[e.to].size(); i++){
            edge ne = adjlist[e.to][i];
            if(dist[ne.to] > dist[ne.from] + ne.w){
                ne.w = dist[ne.to] = dist[ne.from] + ne.w;
                q.push(ne);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}