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
const int mod = int(1e9 + 7);
//const int mod = int(1e6 + 3);
int dcmp(const double &a, const double &b)
{
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}
template<class T, class T2>
T _f_pow(T a, T2 b)
{
    T res = 1LL;
    //a%=mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res*a);//res = (res * a)%mod;
        a = (a * a);
        //a%=mod;
        b >>= 1;
    }
    return (res);
}
//#define iter(x) for(int i = 0; i < (int)x; ++i)
int OO = 0x3f3f3f3f;
const int N = 1e7 + 5;
const int M = 1e5 + 6;
int dp[105][105];
string x, y;
int n, m;
int solve(int i = 0, int j = 0)
{
    if(i >= n || j >= m)return 0;
    int& ret = dp[i][j];
    if(~ret)return ret;
    if(x[i] == y[j])return ret = solve(i + 1, j + 1) + 1;
    ret = max(solve(i + 1, j), solve(i, j + 1));
    return ret;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int tc = 0;
    while(getline(cin, x) && x[0] != '#')
    {
        memset(dp, 0, sizeof(dp));
        getline(cin, y);
        n = sz(x);
        m = sz(y);
        for(int i = n; ~i; --i)
            for(int j = m; ~j; --j)
            {
                if(i == n || j == m)
                    dp[i][j] = 0;
                else if(x[i] == y[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                {
                    if(dp[i + 1][j] > dp[i][j + 1])
                    {
                        dp[i][j] = dp[i + 1][j];
                    }
                    else dp[i][j] = dp[i][j + 1];
                }

            }
        printf("Case #%d: you can visit at most %d cities.\n", ++tc, dp[0][0]);
    }
    //system("sleep 5");
    return 0;
}
