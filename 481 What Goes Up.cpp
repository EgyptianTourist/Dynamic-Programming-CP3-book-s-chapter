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
vector<int> a;
stack<int> st;

int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int x;
    while(cin >> x)
    {
        a.pb(x);
    }
    n = sz(a);
    vector<itn> seq, path(n, 0);
    for(int i = 0; i < n; ++i)
    {
        auto vl = lower_bound(all(seq), a[i]);
        if(vl == seq.end())
            path[i] = sz(seq), seq.pb(a[i]);
        else *vl = a[i], path[i] = vl - seq.begin();
    }
    len = sz(seq) - 1;
    cout << sz(seq) << endl;
    cout << "-" << endl;
    for(int i = n - 1; ~i; --i)
    {
        if(len == path[i])
        {
            st.push(a[i]);
            --len;
        }
    }
    while(st.size())cout << st.top() << endl, st.pop();
    //system("sleep 5");
    return 0;
}
