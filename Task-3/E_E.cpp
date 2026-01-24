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
vi coins;

vector<vi> dp;

int rec(int i, int sum){
    if(i == n) return sum == 0;
    if(sum < 0) return 0;
    int &ret = dp[i][sum];

    if(ret != -1) return ret;

    int op1 = rec(i+1, sum);

    int op2 = rec(i+1, sum - coins[i]);

    return  ret = op1 || op2;
}
void solve(){
    cin >> n;
    coins.resize(n); cin >> coins;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += coins[i];
    }

    dp.assign(n+1, vi(sum+1,-1));

    set<int> distinct;
    for(int i = 1; i <= sum; i++){
        if(rec(0,i)) distinct.insert(i);
    }

    cout << distinct.size() << endl;
    for(auto &it : distinct){
        cout << it << " ";
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}