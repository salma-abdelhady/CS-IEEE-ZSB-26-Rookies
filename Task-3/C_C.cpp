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

int n, x;
vi prices, pages;

vector<vi>dp;

int rec(int i, int rem){
    if(i == n) return 0;

    int &ret = dp[i][rem];

    if(ret != -1) return ret;

    int op1 = 0;
    if(rem - prices[i] >= 0){
        op1 = pages[i] + rec(i+1, rem - prices[i]);
    }
    
    int op2 = rec(i+1, rem);

    return ret = max(op1, op2);
}

void solve(){
    cin >> n >> x;

    prices.resize(n); cin >> prices;
    pages.resize(n); cin >> pages;

    dp.assign(n+1,vi (x+1, -1));

    int ans = rec(0,x);
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}