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

int n, w;
vi values, weights;

vector<vi>dp;

int rec(int i, int mx){
    if(i >= n) return 0;
    
    int &ret = dp[i][mx];

    if(ret != -1) return ret;

    int op1 = rec(i+1,mx);
    int op2 = 0;

    if(weights[i] <= mx)
       op2 = values[i] + rec(i+1, mx - weights[i]);

    return ret = max(op1, op2);
}

void solve(){
    cin >> n >> w;
    values.resize(n); 
    weights.resize(n);

    for(int i = 0; i < n; i++){
        cin >> weights[i] >> values[i];
    }

    dp.assign(n+1, vi(w+1,-1));

    int ans = rec(0,w);
    
    cout << ans;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}