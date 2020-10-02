#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<pair<string, ll> > vsi;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef tuple<ll, ll, ll> ti;
 
 
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}
 
#define EVARS(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}
 
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }
 
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
 
 
#define pb push_back
#define mk make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a)  memset(a, 0, sizeof (a))
#define mod 1000000007
#define ff first
#define ss second
 
 
//Loops
#define REP(i, b) for(ll i=0; i<(ll)(b); i++)
#define F(i, a, b) for(ll i=(ll)(a); i<=(ll)(b); i++)
#define FD(i, a, b) for(ll i=(ll)(a); i>=(ll)(b); i--)
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define RTIME(start, end) ((double)(end-start)/(double)CLOCKS_PER_SEC)
#define D(a) cout<<a<<endl
#define MAX 200015
//#define INF 1e18
 
const ll nmax=1000*1007;
 
 
struct edge
{
    ll a, b, cost;
    edge(ll x, ll y, ll z):a(x), b(y), cost(z) {};
};
 
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);   
 
}
 
 
int main ()
{
    fastio()
 
#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n+1];
        multiset<int> s;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int cur = a[i];
            for(int j = i + 1; j <= n; j++)
            {
                cur += a[j];
                while(s.find(cur) != s.end())
                {
                    ans++;
                    s.erase(s.find(cur));
                }
            }
        }
        cout << ans << endl;
    }   
    return 0;
}