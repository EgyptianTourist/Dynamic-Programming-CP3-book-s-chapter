//#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#ifndef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else

#define debug(...)
#endif
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define ll long long
#define pb push_back
#define EPS 1e-9
#define itn int
const int mod = int(1e9 + 7);
//const int mod = int(1e6 + 3);
int dcmp(const double &a, const double &b)
{
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}
//#define iter(x) for(int i = 0; i < (int)x; ++i)
int OO = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int M = 1e6 + 6;
ll dp[5][30005];
int cent[] = {1, 5, 10, 25, 50};
int n;
ll solve(int i = 0, int rem = n)
{
    if(!rem)return 1LL;
    if(i >= 5)return 0;
    ll& ret = dp[i][rem];
    if(~ret)return ret;
    ret = 0;
    if(rem >= cent[i])
        ret = solve(i, rem - cent[i]);
    ret += solve(i + 1, rem);
    return ret;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    memset(dp, -1, sizeof(dp));
    while(cin >> n)
    {
        //debug(solve());
        ll res = solve();
        cout << res << endl;
    }
    //system("sleep 5");
    return 0;
}
