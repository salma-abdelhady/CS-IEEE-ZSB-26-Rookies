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
int n, m; vector<int> adj[N]; vi color(N);
int cnt1, cnt2;

void classify(int node){
    queue<int> q;
    q.push(node);
    color[node] = 1; cnt1++;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int child: adj[parent]){
            if(color[child] == 0){
                color[child] = 3 - color[parent];
                if(color[child] == 1) cnt1++;
                else cnt2++;
                q.push(child);
            }
        }
    }


}

void solve(){
    cin >> n;
    m = n - 1;
    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    classify(1);

    int ans = (cnt1 * cnt2) - (n-1);
    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
}
