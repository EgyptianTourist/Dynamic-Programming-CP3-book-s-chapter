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
int dp[10005][105];
int a[10005];
int n, k;
int solve(int i, int rem)
{
    if(i >= n)return !rem;
    int& ret = dp[i][rem];
    if(~ret)return ret;
    ret = solve(i + 1, ((rem - a[i]) % k + k) % k);
    ret |= solve(i + 1, ((rem + a[i]) % k + k) % k);
    return ret;
}

int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 0; i < n; ++i)cin >> a[i];
        memset(dp, -1, sizeof(dp));
        puts((solve(1, (a[0] + k) % k) ? "Divisible" : "Not divisible"));
    }
    //system("sleep 5");
    return 0;
}
