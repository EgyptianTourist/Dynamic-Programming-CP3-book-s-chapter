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
const int N = 1e6 + 5;
const int M = 1e6 + 6;
int n, len;
struct type
{
    int x, y, z;
    type(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    bool operator < (type T)
    {
        if(x < T.x && y < T.y)return true;
        if(x < T.y && y < T.x)return true;
        return false;
    }
};
int dp[2005], dp2[2005];
int a[2005];
int solve(int i)
{
    int& ret = dp[i];
    if(~ret)return ret;
    int ret2 = 0;
    for(int j = i; j < n; ++j)
       if(a[i] < a[j]) ret2 = max(ret2, solve(j));
    return ret = ret2 + 1;
}
int solveb(int i)
{
    int& ret = dp2[i];
    if(~ret)return ret;
    int ret2 = 0;
    for(int j = i; j < n; ++j)
        if(a[i] > a[j])ret2 = max(ret2, solveb(j));
    return ret = ret2 + 1;
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
        cin >> n;
        for(int i = 0; i < n; ++i)cin >> a[i];

        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        dp[n] = dp2[n] =1;
        int ans = 0;
        for(int i = 0; i < n; ++i)
            {
                int lis = solve(i);
                int lds =  solveb(i);
                //debug(lis, lds, i);
                ans = max(ans,  lis + lds - 1);
            }
        cout << ans << endl;
    }
    //system("sleep 5");
    return 0;
}
