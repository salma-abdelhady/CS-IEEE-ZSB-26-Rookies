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

int n, k;
vi stones;
vi dp;

int rec(int i){
    if(i == n - 1) return 0;
    
    if(dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    for(int j = i+1; j <= i + k && j < n; j++){
        ans = min(ans, abs(stones[i]- stones[j]) + rec(j));
    }

    dp[i] = ans;
    return ans;
}

void solve(){
    cin >> n >> k;
    stones.resize(n); cin >> stones;
    dp.resize(n,-1);

    int ans = rec(0);
    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}