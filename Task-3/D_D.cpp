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

int n;
vector<vector<char>> grid;
vector<vi> dp;

int rec(int i, int j){
    if(i >= n || j >= n) return 0;
    if(grid[i][j] == '*') return 0;
    if(i == n - 1 && j == n - 1 ) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = (rec(i+1,j) + rec(i, j + 1)) % MOD;
    return (rec(i+1,j) + rec(i, j + 1)) % MOD;
}
void solve(){
    cin >> n;
    grid.assign(n,vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    dp.assign(n+1, vi(n+1,-1));

    int ans = rec(0,0);

    cout << ans;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}