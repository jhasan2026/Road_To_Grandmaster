#include <bits/stdc++.h>

using namespace std;
#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define cinn(x) \
    for (int i = 0; i < x.size(); i++) cin >> x[i];
#define printa(x) \
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
#define LL long long
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define SQR(x) ((x) * (x))
#define loop(i, y) for (int i = 0; i < int(y); i++)
#define FOR(i, x, y) for (int i = int(x); i <= int(y); i++)
#define ROF(i, x, y) for (int i = int(x); i >= int(y); i--)
#define sz(c) int(c.size())
#define clr(x, y) memset(x, y, sizeof(x))
#define si(x) scanf("%d", &x)
#define sii(x, y) scanf("%d %d", &x, &y)
#define siii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sl(x) scanf("%lld", &x)
#define sll(x, y) scanf("%lld %lld", &x, &y)
#define slll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &x : a) in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x : a) out << x << ' ';
    return out;
};

#ifdef VAMP
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define dbg(...)
#endif

template <class T, class L>
inline T bigMod(T p, T e, L M) {
    LL ret = 1 % M;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = ((LL)p * p) % M;
    }
    return (L)ret;
}

/// Constants
#define MAX 200005
#define MOD 1000000007
#define eps 1e-9
#define INF 0x3f3f3f3f3f3f3f3f  // 4,557,430,888,798,830,399
#define inf 0x3f3f3f3f          // 1,061,109,567
#define PI acos(-1.0)           // 3.1415926535897932
#define VT int



LL solve(LL n,LL k){
    LL mid = ceil((double )n/2);
    if(k <= mid){
        return 2*k - 1;
    }
    return 2*(k - mid);

}

int main(){
   LL n,k;
    sll(n,k);
    cout<<solve(n,k);
}


